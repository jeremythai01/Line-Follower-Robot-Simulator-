#include "Pwm.h"

Pwm::Pwm()
{
}

void Pwm::ajustementPWM()
{
    // mise à un des sorties OC1A et OC1B sur comparaison
    // réussie en mode PWM 8 bits, phase correcte
    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6
    // page 177 de la description technique du ATmega324PA)
    OCR1B = 0xFF * vitesseG / 100;
    OCR1A = 0xFF * vitesseD / 100;
    // division d'horloge par 8 - implique une frequence de PWM fixe
    TCCR1A |= (1 << WGM10) | (1 << COM1A1) | (1 << COM1B1);
    TCCR1B |= (1 << CS11);
    TCCR1C = 0;
}

uint8_t Pwm::getVitesseG()
{
    return vitesseG;
}

uint8_t Pwm::getVitesseD()
{
    return vitesseD;
}

void Pwm::setVitesseG(uint8_t vitesseGInit)
{
    vitesseG = vitesseGInit;
}

void Pwm::setVitesseD(uint8_t vitesseDInit)
{
    vitesseD = vitesseDInit;
}

void Pwm::eteindrePwm()
{

    TCCR1A = 0;

    PORTD &= ~(1 << PD4);
    PORTD &= ~(1 << PD5);
}
