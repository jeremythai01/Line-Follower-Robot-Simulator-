#include "Del.h"

Del::Del(Type typeDelInit)
{

    typeDel = typeDelInit;
}

void Del::allumerRouge()
{

    switch (typeDel)
    {

    case GAUCHE:

        PORTD &= ~(1 << PD0);
        PORTD |= (1 << PD1);
        break;

    case DROITE:

        PORTD &= ~(1 << PD2);
        PORTD |= (1 << PD7);
        break;
    }
}

void Del::allumerVert()
{

    switch (typeDel)
    {

    case GAUCHE:

        PORTD &= ~(1 << PD1);
        PORTD |= (1 << PD0);
        break;

    case DROITE:
        PORTD &= ~(1 << PD7);
        PORTD |= (1 << PD2);
        break;
    }
}

void Del::eteindreDels()
{
    PORTD &= ~(1 << PD0);
    PORTD &= ~(1 << PD1);
    PORTD &= ~(1 << PD2);
    PORTD &= ~(1 << PD7);
}
