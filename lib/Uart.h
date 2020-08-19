#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <util/delay.h>
#include <util/delay_basic.h>

class Uart
{

public:
    Uart();
    void transmissionUART(uint8_t donnee);
    uint8_t receptionUART();

private:
    // Donnees membres - aucun
};

#endif
