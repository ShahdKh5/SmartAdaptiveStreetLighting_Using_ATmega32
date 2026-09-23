#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../01-MCAL/00-LIB/STD_TYPES.h"
#include "APP_interface.h"

int main(void)
{
    APP_voidSystemInit();

    while (1)
    {
        APP_voidControlLighting();
        _delay_ms(50);
    }

    return 0;
}
