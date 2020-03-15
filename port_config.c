/*This C file contains a function responsible to configure
all the ports being used*/
#include "ml4_header.h"
void port_config()
{
    // Power Window
    SET_BIT(DDRC,PC5);  // output
    CLR_BIT(DDRB,PB0);  // obstacle
    SET_BIT(PORTB,PB0); // pull up
    CLR_BIT(DDRD,PD1);  // rain
    SET_BIT(PORTD,PD1);  // pull up
    CLR_BIT(DDRB,PB6); // power window up
    SET_BIT(PORTB,PB6); // pull up
    CLR_BIT(DDRB,PB7);  // power window down
    SET_BIT(PORTB,PB7); // pull up

    //TPMS
    SET_BIT(DDRD,PD4);  // Tire Pressure Indicator - Output
    SET_BIT(DDRD,PD5);  // Tire Temperature Indicator - Output

    // HVAC & Seat Adjustment
    CLR_BIT(DDRD,PD3);
    CLR_BIT(DDRD,PD2);
    SET_BIT(PORTD,PD3);
    SET_BIT(PORTD,PD2);

    SET_BIT(DDRC,PC6);
    SET_BIT(DDRD,PD0);
    SET_BIT(DDRD,PD6);
    SET_BIT(DDRB,PB1);


    SET_BIT(DDRB,PB2);
    SET_BIT(DDRB,PB3);
    SET_BIT(DDRB,PB4);
    SET_BIT(DDRB,PB5);
    CLR_BIT(DDRC,PC0);
    SET_BIT(PORTC,PC0);  // seat position controller

    SET_BIT(PORTC,PC2);   // Pressure sensor pot value
    SET_BIT(PORTC,PC3);   // Temperature sensor pot value
    SET_BIT(PORTC,PC4);   // HVAC Mode

    EICRA|=(1<<ISC11);  //int1  falling edge
    EICRA|=(1<<ISC01);  // int0 falling edge

    EIMSK|=(1<<INT1);
    EIMSK|=(1<<INT0);

    TCCR0A|=((1<<WGM01) | (1<<WGM00));  //fast pwm
    TCCR0A|=(1<<COM0A1);   //non inverting
    TCNT0=0x00;
    TCCR0B|=((1<<CS00)|(1<<CS02));  // clock pre-scaler 1024
    sei();  // global interrupt enable
}
