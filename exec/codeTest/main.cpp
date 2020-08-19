#define F_CPU 8000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Del.h"
#include "Detection.h"
#include "Pwm.h"
#include "lcm_so1602dtr_m_fw.h"
#include "Afficheur7segment.h"
#include "Manoeuvre.h"

const uint16_t ANTI_REBOND = 30;
const uint16_t QUART_DE_SECONDE = 250;
volatile bool enModeDetection;

void laisserPasser(int dureeEnMs);
void initialisation(void);

ISR(INT1_vect)
{

        // anti-rebond
        laisserPasser(ANTI_REBOND);

        enModeDetection = false;

        EIFR |= (1 << INTF1);
}

int main()
{

        Detection detection;
        initialisation();
        LCM disp(&DDRB, &PORTB);

        Manoeuvre manoeuvre;
        Del delG(GAUCHE);
        Del delD(DROITE);
        Pwm pwm;
        uint8_t numManoeuvre;

        for (;;)
        {
                if (enModeDetection == true)
                {
                        detection.eteindreComposantes();
                        detection.detecterSonars();
                        detection.afficher(disp);
                        laisserPasser(QUART_DE_SECONDE); // 4 tours par secondes
                }
                else
                {
                        numManoeuvre = manoeuvre.trouverNumManoeuvre(detection.getCategorieG(), detection.getCategorieA(), detection.getCategorieD());

                        if (numManoeuvre != 0)
                        {
                                disp.afficherManoeuvre(numManoeuvre);
                                manoeuvre.effectuerManoeuvre(numManoeuvre, pwm, delG, delD);
                        }
                        else
                        {
                                disp.afficherAucuneManoeuvre();
                                laisserPasser(2000);
                        }
                        enModeDetection = true;
                }
        }

        return 0;
}

void initialisation(void)
{

        // cli est une routine qui bloque toutes les interruptions.
        cli();

        // configurer et choisir les ports pour les entrées

        // et les sorties. DDRx... Initialisez bien vos variables

        enModeDetection = true;
        DDRA = 0xf8;
        DDRC = 0xff;
        DDRD = 0xb7;
        DDRB = 0xff;

        // cette procédure ajuste le registre EIMSK

        // de l’ATmega324PA pour permettre les interruptions externes

        EIMSK |= (1 << INT1);

        // il faut sensibiliser les interruptions externes aux

        // changements de niveau du bouton-poussoir

        // en ajustant le registre EICRA

        EICRA |= (1 << ISC00) | (1 << ISC11);
        // sei permet de recevoir à nouveau des interruptions.
        sei();
}

void laisserPasser(int dureeEnMs)
{
        for (int i = 0; i < dureeEnMs; i++)
        {
                _delay_ms(1);
        }
}
