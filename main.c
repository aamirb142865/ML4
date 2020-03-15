/*This C file is the main file of the ML4 integrated embedded C implementation

Version: 1.0
Authors:
        Nitesh Dhiman (Seat Adjustment)
        Aamir Suhail Burhan - (TPMS)
        Darshan N - (HVAC)
        Darrel Reesha Pinto - (Power Window)
*/
#include "ml4_header.h"
int main()
{
    value = 128;
    port_config();
    while(1)
    {
        isr_action(); // check for isr
        seat();  // execute seat feature
        hvac();  // execute hvac feature
        if(adc4<768)
            OCR0A = value;  // initiate hvac
        window();  // execute power window feature
        tpms();  // execute tpms feature
        _delay_ms(100);
    }
    return 0;
}



