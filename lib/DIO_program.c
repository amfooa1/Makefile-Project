/***********************************************************/
/***************  Name   : Ahmed Fathi *********************/
/***************  Date   : 30/5/2021  **********************/
/***************  SWC    : DIO        **********************/
/***********************************************************/  

#include "DIO_private.h"



/* MCAL */
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"




static volatile u8* directionRegisters[4] = {DDRA_Register, DDRB_Register, DDRC_Register, DDRD_Register};
static volatile u8* outputRegisters[4] = {PORTA_Register, PORTB_Register, PORTC_Register, PORTD_Register};
static volatile u8* inputRegisters[4] = {PINA_Register, PINB_Register, PINC_Register, PIND_Register};

void DIO_init(void)
{
	*directionRegisters[PA] = Conc(PA7_INTIAL_DIRECTION,PA6_INTIAL_DIRECTION,PA5_INTIAL_DIRECTION,PA4_INTIAL_DIRECTION,
						   PA3_INTIAL_DIRECTION,PA2_INTIAL_DIRECTION,PA1_INTIAL_DIRECTION,PA0_INTIAL_DIRECTION);

	*directionRegisters[PB] = Conc(PB7_INTIAL_DIRECTION,PB6_INTIAL_DIRECTION,PB5_INTIAL_DIRECTION,PB4_INTIAL_DIRECTION,
						   PB3_INTIAL_DIRECTION,PB2_INTIAL_DIRECTION,PB1_INTIAL_DIRECTION,PB0_INTIAL_DIRECTION);

	*directionRegisters[PC] = Conc(PC7_INTIAL_DIRECTION,PC6_INTIAL_DIRECTION,PC5_INTIAL_DIRECTION,PC4_INTIAL_DIRECTION,
						   PC3_INTIAL_DIRECTION,PC2_INTIAL_DIRECTION,PC1_INTIAL_DIRECTION,PC0_INTIAL_DIRECTION);

	*directionRegisters[PD] = Conc(PD7_INTIAL_DIRECTION,PD6_INTIAL_DIRECTION,PD5_INTIAL_DIRECTION,PD4_INTIAL_DIRECTION,
						   PD3_INTIAL_DIRECTION,PD2_INTIAL_DIRECTION,PD1_INTIAL_DIRECTION,PD0_INTIAL_DIRECTION);

	*outputRegisters[PA] = Conc(PA7_INTIAL_VALUE,PA6_INTIAL_VALUE,PA5_INTIAL_VALUE,PA4_INTIAL_VALUE,
						   PA3_INTIAL_VALUE,PA2_INTIAL_VALUE,PA1_INTIAL_VALUE,PA0_INTIAL_VALUE);

	*outputRegisters[PB] = Conc(PB7_INTIAL_VALUE,PB6_INTIAL_VALUE,PB5_INTIAL_VALUE,PB4_INTIAL_VALUE,
						   PB3_INTIAL_VALUE,PB2_INTIAL_VALUE,PB1_INTIAL_VALUE,PB0_INTIAL_VALUE);

	*outputRegisters[PC] = Conc(PC7_INTIAL_VALUE,PC6_INTIAL_VALUE,PC5_INTIAL_VALUE,PC4_INTIAL_VALUE,
						   PC3_INTIAL_VALUE,PC2_INTIAL_VALUE,PC1_INTIAL_VALUE,PC0_INTIAL_VALUE);

	*outputRegisters[PD] = Conc(PD7_INTIAL_VALUE,PD6_INTIAL_VALUE,PD5_INTIAL_VALUE,PD4_INTIAL_VALUE,
						   PD3_INTIAL_VALUE,PD2_INTIAL_VALUE,PD1_INTIAL_VALUE,PD0_INTIAL_VALUE);
}


void DIO_changePinDirection(u8 a_pinNo, u8 a_direction)
{
	/*Safety Condition to make sure user inputs a valid pin number*/
	if(a_pinNo >= A0 && a_pinNo <= D7)
	{
		/*Change pin Mode according to function input*/
		switch(a_direction)
		{
			/*Clear bit in direction register specified by pin number input*/
			case INPUT:        CLR_BIT(*directionRegisters[a_pinNo>>3],(a_pinNo & 0x07));
						       break;
		    /*Set bit in direction register specified by pin number input*/
			case OUTPUT:       SET_BIT(*directionRegisters[a_pinNo>>3],(a_pinNo & 0x07));
						       break;
		    /*Clear bit in direction register specified by pin number input*/
		    /*Set bit in output register specified by pin number input*/
			case INPUT_PULLUP: CLR_BIT(*directionRegisters[a_pinNo>>3],(a_pinNo & 0x07));
							   SET_BIT(*outputRegisters[a_pinNo>>3],(a_pinNo & 0x07));
							   break;
		}
	}
}

void DIO_writePinState(u8 a_pinNo, u8 a_state)
{
	if(a_pinNo >= A0 && a_pinNo <= D7)
	{
		switch(a_state)
		{
			case LOW:  CLR_BIT(*outputRegisters[a_pinNo>>3],(a_pinNo & 0x07));
				       break;
			case HIGH: SET_BIT(*outputRegisters[a_pinNo>>3],(a_pinNo & 0x07));
					   break;

		}
	}
}

u8 DIO_getPinState(u8 a_pinNo)
{
	if(a_pinNo >= A0 && a_pinNo <= D7)
	{
		return GET_BIT(*inputRegisters[a_pinNo>>3],(a_pinNo & 0x07));
	}else
	{
		return 0xFF;
	}
}

void DIO_togglePinState(u8 a_pinNo)
{
	if(a_pinNo >= A0 && a_pinNo <= D7)
	{
		TOG_BIT(*outputRegisters[a_pinNo>>3],(a_pinNo & 0x07));
	}
}

void DIO_changePortDirection(u8 a_portNo, u8 a_direction)
{
	if(a_portNo >= PA && a_portNo <= PD)
	{
		*directionRegisters[a_portNo] = a_direction;
	}
}

void DIO_writePortState(u8 a_portNo, u8 a_state)
{
	if(a_portNo >= PA && a_portNo <= PD)
	{
		*outputRegisters[a_portNo] = a_state;
	}
}

u8 DIO_getPortState(u8 a_portNo)
{
	if(a_portNo >= PA && a_portNo <= PD)
	{
		return *inputRegisters[a_portNo];
	}else
	{
		return 0xFF;
	}
}

void DIO_togglePortState(u8 a_portNo)
{
	if(a_portNo >= PA && a_portNo <= PD)
	{
		*outputRegisters[a_portNo] = ~(*outputRegisters[a_portNo]);
	}
}
