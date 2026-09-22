#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../01-MCAL/00-LIB/STD_TYPES.h"
#include "APP_interface.h"

int main(void) {
    /* Initialize the system */
    /* APP_voidSystemInit(); */
    
    while(1) {
        /* TODO: 
           1. Call APP_voidControlLighting() to manage the adaptive illumination.
           2. Call APP_voidUpdateDisplay() to refresh the LCD.
           3. Add a small delay for stability.
        */
    }
    
    return 0;
}
