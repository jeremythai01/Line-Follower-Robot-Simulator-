#include "Manoeuvre.h"

ISR(TIMER2_OVF_vect)
{
  Afficheur7segment seg(vitesseG_, vitesseD_);
}

Manoeuvre::Manoeuvre() {}

uint8_t Manoeuvre::trouverNumManoeuvre(const char *cat1, const char *cat2, const char *cat3)
{

  uint8_t manRetourne = 0;

  if (cat1 == "OK" && cat2 == "OK" && cat3 == "ATTN")
    manRetourne = 1;
  if (cat1 == "ATTN" && cat2 == "OK" && cat3 == "OK")
    manRetourne = 2;
  if (cat1 == "OK" && cat2 == "DNGR" && cat3 == "DNGR")
    manRetourne = 3;
  if (cat1 == "DNGR" && cat2 == "DNGR" && cat3 == "OK")
    manRetourne = 4;
  if (cat1 == "DNGR" && cat2 == "DNGR" && cat3 == "DNGR")
    manRetourne = 5;
  if (cat1 == "ATTN" && cat2 == "OK" && cat3 == "ATTN")
    manRetourne = 6;

  return manRetourne;
}

void Manoeuvre::effectuerManoeuvre(uint8_t num, Pwm &pwm, Del &delG, Del &delD)
{

  //Mise des pins du PWM à 1
  PORTD |= (1 << PD4);
  PORTD |= (1 << PD5);

  switch (num)
  {
  case 1:
    manoeuvre1(pwm, delG, delD);
    break;
  case 2:
    manoeuvre2(pwm, delG, delD);
    break;
  case 3:
    manoeuvre3(pwm, delG, delD);
    break;
  case 4:
    manoeuvre4(pwm, delG, delD);
    break;
  case 5:
    manoeuvre5(pwm, delG, delD);
    break;
  case 6:
    manoeuvre6(pwm, delG, delD);
    break;
  }
}

void Manoeuvre::manoeuvre1(Pwm &pwm, Del &delG, Del &delD)
{

  pwm.setVitesseG(90);
  pwm.setVitesseD(90);
  partirMinuterie(CENTUS);
  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();

  delG.allumerVert();
  delD.allumerVert();

  while (pwm.getVitesseG() > 52)
  {
    pwm.setVitesseG(pwm.getVitesseG() - 1);
    pwm.ajustementPWM();
    vitesseG_ = pwm.getVitesseG();
    laisserPasser(100);
  }

  laisserPasser(1000);

  while (pwm.getVitesseG() < 90)
  {
    pwm.setVitesseG(pwm.getVitesseG() + 1);
    pwm.ajustementPWM();
    vitesseG_ = pwm.getVitesseG();
    laisserPasser(100);
  }

  laisserPasser(2000);
  TIMSK2 &= ~(1 << TOIE2);
}

void Manoeuvre::manoeuvre2(Pwm &pwm, Del &delG, Del &delD)
{
  pwm.setVitesseG(90);
  pwm.setVitesseD(90);
  partirMinuterie(CENTUS);
  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();

  delG.allumerVert();
  delD.allumerVert();

  while (pwm.getVitesseD() > 52)
  {

    pwm.setVitesseD(pwm.getVitesseD() - 1);
    pwm.ajustementPWM();
    vitesseD_ = pwm.getVitesseD();

    laisserPasser(100);
  }
  laisserPasser(1000);

  while (pwm.getVitesseD() < 90)
  {

    pwm.setVitesseD(pwm.getVitesseD() + 1);
    pwm.ajustementPWM();
    vitesseD_ = pwm.getVitesseD();

    laisserPasser(100);
  }

  laisserPasser(2000);
  TIMSK2 &= ~(1 << TOIE2);
}
void Manoeuvre::manoeuvre3(Pwm &pwm, Del &delG, Del &delD)
{
  pwm.setVitesseG(50);
  pwm.setVitesseD(50);
  partirMinuterie(CENTUS);
  pwm.ajustementPWM();
  vitesseG_ = (pwm.getVitesseG());
  vitesseD_ = pwm.getVitesseD();

  delG.allumerRouge();
  delD.allumerVert();
  laisserPasser(1000);

  pwm.setVitesseG(66);
  pwm.setVitesseD(66);

  pwm.ajustementPWM();

  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();
  delG.allumerVert();
  laisserPasser(2000);

  pwm.setVitesseG(50);
  pwm.setVitesseD(50);

  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();
  delD.allumerRouge();
  laisserPasser(1000);

  pwm.setVitesseG(78);
  pwm.setVitesseD(78);
  pwm.ajustementPWM();

  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();

  delD.allumerVert();
  laisserPasser(2000);
  TIMSK2 &= ~(1 << TOIE2);
}
void Manoeuvre::manoeuvre4(Pwm &pwm, Del &delG, Del &delD)
{
  pwm.setVitesseG(50);
  pwm.setVitesseD(50);
  partirMinuterie(CENTUS);
  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();

  delG.allumerVert();
  delD.allumerRouge();
  laisserPasser(1000);

  pwm.setVitesseG(66);
  pwm.setVitesseD(66);
  pwm.ajustementPWM();

  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();

  delD.allumerVert();
  laisserPasser(2000);

  pwm.setVitesseG(50);
  pwm.setVitesseD(50);
  pwm.ajustementPWM();

  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();
  delG.allumerRouge();
  laisserPasser(1000);

  pwm.setVitesseG(78);
  pwm.setVitesseD(78);
  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();
  delG.allumerVert();
  laisserPasser(2000);
  TIMSK2 &= ~(1 << TOIE2);
}
void Manoeuvre::manoeuvre5(Pwm &pwm, Del &delG, Del &delD)
{
  pwm.setVitesseG(50);
  pwm.setVitesseD(50);
  partirMinuterie(CENTUS);
  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();
  delG.allumerVert();
  delD.allumerRouge();
  laisserPasser(2000);

  pwm.setVitesseG(0);
  pwm.setVitesseD(0);
  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();
  delG.allumerVert();
  delD.allumerVert();

  while (pwm.getVitesseG() < 63 && pwm.getVitesseD() < 63)
  {
    pwm.setVitesseG(pwm.getVitesseG() + 3);
    pwm.setVitesseD(pwm.getVitesseD() + 3);
    pwm.ajustementPWM();
    vitesseG_ = pwm.getVitesseG();
    vitesseD_ = pwm.getVitesseD();
    laisserPasser(125);
  }

  laisserPasser(2000);
  TIMSK2 &= ~(1 << TOIE2);
}

void Manoeuvre::manoeuvre6(Pwm &pwm, Del &delG, Del &delD)
{

  pwm.setVitesseG(90);
  pwm.setVitesseD(90);
  partirMinuterie(CENTUS);
  pwm.ajustementPWM();
  vitesseG_ = pwm.getVitesseG();
  vitesseD_ = pwm.getVitesseD();

  delG.allumerRouge();
  delD.allumerRouge();

  while (pwm.getVitesseG() > 41 && pwm.getVitesseD() > 41)
  {
    pwm.setVitesseG(pwm.getVitesseG() - 7);
    pwm.setVitesseD(pwm.getVitesseD() - 7);
    pwm.ajustementPWM();
    vitesseG_ = pwm.getVitesseG();
    vitesseD_ = pwm.getVitesseD();
    laisserPasser(500);
  }

  laisserPasser(2000);
  TIMSK2 &= ~(1 << TOIE2);
}

void Manoeuvre::laisserPasser(int dureeEnMs)
{
  for (int i = 0; i < dureeEnMs; i++)
  {
    _delay_ms(1);
  }
}

void Manoeuvre::partirMinuterie(uint8_t duree)
{

  TCNT2 = 0;
  OCR2A = duree;
  TCCR2A |= (1 << WGM21) | (1 << COM2A0);
  // prescaler = 1024
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

  // enable overflow interrupt
  TIMSK2 |= (1 << TOIE2);

  // enable global interrupts
  sei();
}