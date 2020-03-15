/*This header file contains the declarations of header files,
macros, flag bits and variables*/
#ifndef ML4_HEADER_H_INCLUDED
#define ML4_HEADER_H_INCLUDED
#include<avr/io.h>
#include<util/delay.h>
#include<stdint.h>
#include<avr/interrupt.h>
#define SET_BIT(port,val) port|=(1<<val)
#define CLR_BIT(port,val) port&=~(1<<val)
struct
{
    volatile unsigned int FLAG_ISR1:1;
    volatile unsigned int FLAG_ISR0:1;
} FLAG_BIT;
volatile unsigned int adc2;    // Tire Pressure ADC value
volatile unsigned int adc3;    // Tire Temperature ADC value
volatile unsigned int adc4;    // AC Mode
volatile unsigned int ADC_value_seat;       // Seat position change mode
volatile unsigned int value;  // PWM Initial Value
void port_config(void);  //  function prototyping
void isr_action(void);
void seat(void);
void window(void);
void tpms(void);
void hvac(void);
#endif
