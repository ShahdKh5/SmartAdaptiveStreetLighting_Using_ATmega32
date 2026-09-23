#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/* Flash this SAME slave code onto both remaining boards.
   The ONLY thing that changes between them is this line:
     - Board driving Zone2 -> SLAVE_u8_MY_ZONE = LINK_u8_ZONE2
     - Board driving Zone3 -> SLAVE_u8_MY_ZONE = LINK_u8_ZONE3
   (LINK_u8_ZONE2 / LINK_u8_ZONE3 are defined in LINK_protocol.h) */
#include "LINK_protocol.h"

#define SLAVE_u8_MY_ZONE   LINK_u8_ZONE2

#endif
