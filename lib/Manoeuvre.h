/*
 * Classe permettant l'acces au manoeuvres du robot
 */

#ifndef MANOEUVRE_H
#define MANOEUVRE_H

#include <avr/io.h>
#include "Del.h"
#include "Pwm.h"
#include "Afficheur7segment.h"
/*
 * Classe Manoeuvre:
 *   Le constructeur initialise la manoeuvre.
 *
 */

static volatile uint8_t vitesseG_;
static volatile uint8_t vitesseD_;

class Manoeuvre
{
public:
   Manoeuvre();
   void effectuerManoeuvre(uint8_t num, Pwm &pwm, Del &delG, Del &delD);
   uint8_t trouverNumManoeuvre(const char *cat1, const char *cat2, const char *cat3);

private:
   void manoeuvre1(Pwm &pwm, Del &delG, Del &delD);
   void manoeuvre2(Pwm &pwm, Del &delG, Del &delD);
   void manoeuvre3(Pwm &pwm, Del &delG, Del &delD);
   void manoeuvre4(Pwm &pwm, Del &delG, Del &delD);
   void manoeuvre5(Pwm &pwm, Del &delG, Del &delD);
   void manoeuvre6(Pwm &pwm, Del &delG, Del &delD);
   void laisserPasser(int dureeEnMs);
   void partirMinuterie(uint8_t duree);
};

#endif