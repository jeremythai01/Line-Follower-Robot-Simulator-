#include "Afficheur7segment.h"

Afficheur7segment::Afficheur7segment(uint8_t vitesseG, uint8_t vitesseD)
{
    vitesseG_ = vitesseG;
    vitesseD_ = vitesseD;
    afficher();
    //partirMinuterie(40);
}

uint8_t Afficheur7segment::obtenirChiffre(uint8_t chiffre)
{
    uint8_t num = 0;

    switch (chiffre)
    {
    case 0:
        num = zero;
        break;

    case 1:
        num = un;
        break;

    case 2:
        num = deux;
        break;

    case 3:
        num = trois;
        break;

    case 4:
        num = quatre;
        break;

    case 5:
        num = cinq;
        break;

    case 6:
        num = six;
        break;

    case 7:
        num = sept;
        break;

    case 8:
        num = huit;
        break;

    case 9:
        num = neuf;
        break;

    default:
        num = tiret;
        break;
    }

    return num;
}

void Afficheur7segment::afficher()
{
    PORTA = (0xFF & ~(1 << (counter + 3)));

    if (counter == 0)
    {
        uint8_t dizaineG = vitesseG_ / 10;
        uint8_t premierG = obtenirChiffre(dizaineG);
        PORTC = premierG;
    }

    if (counter == 1)
    {
        uint8_t uniteG = vitesseG_ % 10;
        uint8_t deuxiemeG = obtenirChiffre(uniteG);
        PORTC = deuxiemeG;
    }

    if (counter == 2)
    {
        PORTC = tiret;
    }

    if (counter == 3)
    {
        uint8_t dizaineD = vitesseD_ / 10;
        uint8_t premierD = obtenirChiffre(dizaineD);
        PORTC = premierD;
    }

    if (counter == 4)
    {
        uint8_t uniteD = vitesseD_ % 10;
        uint8_t deuxiemeD = obtenirChiffre(uniteD);
        PORTC = deuxiemeD;
    }

    counter++;
    counter%= 5;
}
