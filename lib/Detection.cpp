#include "Detection.h"

Detection::Detection()
{
}

void Detection::eteindreComposantes()
{
    Del::eteindreDels();
    Pwm::eteindrePwm();
    PORTC = ETEINDRE;
}

void Detection::detecterSonars()
{
    detecterG();
    _delay_ms(65);
    detecterA();
    _delay_ms(65);
    detecterD();
    _delay_ms(65);
}

void Detection::detecterG()
{
    PORTB = ALLUMER;
    _delay_us(10);
    PORTB = ETEINDRE;

    bool limiteAtteinte = false;
    compteur = 0;

    while (!(PINA & ALLUMER))
    {
    }
    while ((PINA & ALLUMER))
    {
        if (compteur > COMPTEURMAX)
        {
            limiteAtteinte = true;
            distanceG = 0;
            break;
        }
        else
        {
            compteur++;
            _delay_us(1);
        }
    }

    if (limiteAtteinte == false)
    {
        distanceG = compteur / CONVERTIRMETRE;
    }
    PINA &= ~(1 << PA0);
}

void Detection::detecterA()
{
    PORTB = ALLUMER;
    _delay_us(10);
    PORTB = ETEINDRE;
    bool limiteAtteinte = false;
    compteur = 0;
    while (!(PINA & PA1ALLUMER))
    {
    }
    while ((PINA & PA1ALLUMER))
    {
        if (compteur > COMPTEURMAX)
        {
            limiteAtteinte = true;
            distanceA = 0;
            break;
        }
        else
        {
            compteur++;
            _delay_us(1);
        }
    }
    if (limiteAtteinte == false)
    {
        distanceA = compteur / CONVERTIRMETRE;
    }
    PINA &= ~(1 << PA0);
}

void Detection::detecterD()
{
    PORTB = ALLUMER;
    _delay_us(10);
    PORTB = ETEINDRE;

    bool limiteAtteinte = false;

    compteur = 0;

    while (!(PINA & PA2ALLUMER))
    {
    }
    while ((PINA & PA2ALLUMER))
    {
        if (compteur > COMPTEURMAX)
        {
            limiteAtteinte = true;
            distanceD = 0;
            break;
        }
        else
        {
            compteur++;
            _delay_us(1);
        }
    }
    if (limiteAtteinte == false)
    {
        distanceD = compteur / CONVERTIRMETRE;
    }
    PINA &= ~(1 << PA0);
}

void Detection::comparerG()
{
    if (distanceG < 1)
    {
        categorieG = "DNGR";
    }
    else if (distanceG >= 3)
    {
        categorieG = "OK";
    }
    else
    {
        categorieG = "ATTN";
    }
}

void Detection::comparerA()
{
    if (distanceA < 1)
    {
        categorieA = "DNGR";
    }
    else if (distanceA >= 3)
    {
        categorieA = "OK";
    }
    else
    {
        categorieA = "ATTN";
    }
}

void Detection::comparerD()
{
    if (distanceD < 1)
    {
        categorieD = "DNGR";
    }
    else if (distanceD >= 3)
    {
        categorieD = "OK";
    }
    else
    {
        categorieD = "ATTN";
    }
}

void Detection::afficher(LCM &affichageLcd)
{
    comparerG();
    comparerA();
    comparerD();
    affichageLcd.afficherDetection(distanceG, distanceA, distanceD, categorieG, categorieA, categorieD);
}

char *Detection::getCategorieG()
{
    return categorieG;
}
char *Detection::getCategorieA()
{
    return categorieA;
}
char *Detection::getCategorieD()
{
    return categorieD;
}
