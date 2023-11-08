/***********************************************************/
/***************  Name   : Ahmed Fathi *********************/
/***************  Date   : 30/5/2021  **********************/
/***************  SWC    : DIO        **********************/
/***********************************************************/  
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

/*Ports Register Addressing*/
#define PORTA_Register  ((volatile u8*)0x3B)
#define DDRA_Register   ((volatile u8*)0x3A)
#define PINA_Register   ((volatile u8*)0x39)

#define PORTB_Register  ((volatile u8*)0x38)
#define DDRB_Register   ((volatile u8*)0x37)
#define PINB_Register   ((volatile u8*)0x36)

#define PORTC_Register  ((volatile u8*)0x35)
#define DDRC_Register   ((volatile u8*)0x34)
#define PINC_Register   ((volatile u8*)0x33)

#define PORTD_Register  ((volatile u8*)0x32)
#define DDRD_Register   ((volatile u8*)0x31)
#define PIND_Register   ((volatile u8*)0x30)

/*Define Pin Modes*/
enum PINS_DIRECTIONS
{
	INPUT, OUTPUT, INPUT_PULLUP
};

/*Define Pin States*/
enum PINS_STATES
{
	LOW = (0u), HIGH = (1u)
};

#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)           Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif
