#ifndef LINK_PROTOCOL_H
#define LINK_PROTOCOL_H

/* One status byte, broadcast by the MASTER over USART every ~100ms.
   Both SLAVE boards listen to the same line and decode it identically.
   MUST stay identical between MASTER/03-APP and SLAVE/03-APP. */

/* bit7        : 1 = night, 0 = day                                */
#define LINK_u8_NIGHT_BIT      7
/* bit6        : 1 = manual mode, 0 = auto mode                    */
#define LINK_u8_MANUAL_BIT     6
/* bits5-4     : which zone is targeted in manual mode (0,1,2)     */
#define LINK_u8_ZONE_SHIFT     4
#define LINK_u8_ZONE_MASK      0x03
/* bits3-2     : requested level for that zone (OFF=0,LOW=1,HIGH=2)*/
#define LINK_u8_LEVEL_SHIFT    2
#define LINK_u8_LEVEL_MASK     0x03

/* Zone indices used inside the protocol (master's own zone = 0) */
#define LINK_u8_ZONE1   0   /* master's own local zone   */
#define LINK_u8_ZONE2   1   /* first slave board         */
#define LINK_u8_ZONE3   2   /* second slave board        */

#endif
