#ifndef MINUTERIE_H
#define MINUTERIE_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

class Minuterie
{
public:
    void partirMinuterie(uint16_t duree);

private:
    // Donnees membres - aucun
};

#endif
