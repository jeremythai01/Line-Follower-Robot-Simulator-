#ifndef DEL_H
#define DEL_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

enum Type
{
    GAUCHE,
    DROITE
};

class Del
{
public:
    Del(Type typeDelInit);
    void allumerRouge();
    void allumerVert();
    static void eteindreDels();

private:
    Type typeDel;
};
#endif