#ifndef DEMUX_CONFIG_H
#define DEMUX_CONFIG_H

/* Define DIO Ports and Pins connected to Select Pins */
#define DEMUX_S0_PORT    DIO_PORTA
#define DEMUX_S0_PIN     DIO_PIN0

#define DEMUX_S1_PORT    DIO_PORTA
#define DEMUX_S1_PIN     DIO_PIN1

#define DEMUX_S2_PORT    DIO_PORTA
#define DEMUX_S2_PIN     DIO_PIN2

/* Define Enable Pin (if applicable) */
#define DEMUX_EN_PORT    DIO_PORTA
#define DEMUX_EN_PIN     DIO_PIN3

#endif