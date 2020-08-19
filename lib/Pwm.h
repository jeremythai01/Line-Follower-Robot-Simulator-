#ifndef PWM_H
#define PWM_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

class Pwm
{
public:

    Pwm();

    void ajustementPWM();
    uint8_t getVitesseD();
    uint8_t getVitesseG();
    void setVitesseD(uint8_t vitesseD);
    void setVitesseG(uint8_t vitesseG);
    static void eteindrePwm();

private:
    uint8_t vitesseG;
    uint8_t vitesseD;
};

#endif