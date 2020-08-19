#include "can.h"
#include "Pwm.h"
#include "Del.h"
#include "lcm_so1602dtr_m_fw.h"

const uint8_t ETEINDRE = 0x00;
const uint8_t ALLUMER = 0x01;
const uint16_t COMPTEURMAX = 7200;
const double CONVERTIRMETRE = 1720.0;
const uint8_t PA1ALLUMER = 0x02;
const uint8_t PA2ALLUMER = 0x04;

class Detection
{
public:
    Detection();
    void afficher(LCM &affichageLcd);
    void eteindreComposantes();
    void detecterSonars();
    char *getCategorieA();
    char *getCategorieG();
    char *getCategorieD();

private:
    double distanceG;
    double distanceD;
    double distanceA;
    char *categorieG;
    char *categorieA;
    char *categorieD;
    int compteur;

    void detecterG();
    void detecterA();
    void detecterD();
    void comparerG();
    void comparerA();
    void comparerD();
};