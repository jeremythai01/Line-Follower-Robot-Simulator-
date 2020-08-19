#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

    static const uint16_t CENTUS = 1;
    static const int zero = 0b11111100;
    static const int un = 0b01100000;
    static const int deux = 0b11011010;
    static const int trois = 0b11110010;
    static const int quatre = 0b01100110;
    static const int cinq = 0b10110110;
    static const int six = 0b10111110;
    static const int sept = 0b11100000;
    static const int huit = 0b11111110;
    static const int neuf = 0b11100110;
    static const int tiret = 0b00000010;
    static volatile uint8_t counter = 0;  
class Afficheur7segment
{
 
public:

    Afficheur7segment(uint8_t vitesseG, uint8_t vitesseD);
    uint8_t obtenirChiffre(uint8_t chiffre);
    void afficher();

private:
    uint8_t vitesseG_;
    uint8_t vitesseD_;
};

#endif