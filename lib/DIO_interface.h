/***********************************************************/
/***************  Name   : Ahmed Fathi *********************/
/***************  Date   : 30/5/2021  **********************/
/***************  SWC    : DIO        **********************/
/***********************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/*Define Port Numbers*/
enum PORTS
{
	PA, PB, PC, PD
};

/*Define Pin Numbers*/
enum PINS
{
	A0, A1, A2, A3, A4, A5, A6, A7,
	B0, B1, B2, B3, B4, B5, B6, B7,
	C0, C1, C2, C3, C4, C5, C6, C7,
	D0, D1, D2, D3, D4, D5, D6, D7
};

/*Define Port Modes*/
enum PORTS_DIRECTIONS
{
	PORT_INPUT = 0 , PORT_OUTPUT = 0xFF
};

/*Define Port States*/
enum PORTS_STATES
{
	PORT_LOW = 0, PORT_HIGH = 0xFF
};

//Function Prototypes

void DIO_changePinDirection(u8 a_pinNo, u8 a_direction);

void DIO_writePinState(u8 a_pinNo, u8 a_state);

u8 DIO_getPinState(u8 a_pinNo);

void DIO_togglePinState(u8 a_pinNo);

void DIO_changePortDirection(u8 a_port, u8 a_direction);

void DIO_writePortState(u8 a_port, u8 a_state);

u8 DIO_getPortState(u8 a_port);

void DIO_togglePortState(u8 a_port);


#endif
