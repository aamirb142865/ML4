/*This C file contains interrupt service routines*/
#include "ml4_header.h"
ISR(INT0_vect)  // ISR for incrementing HVAC intensity by 5%
{
    cli();
    FLAG_BIT.FLAG_ISR0=1;
    sei();
}
ISR(INT1_vect)  // ISR for decrementing HVAC intensity by 5%
{
    cli();
    FLAG_BIT.FLAG_ISR1=1;
    sei();
}


