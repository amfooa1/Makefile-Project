#include <avr/io.h>
#define F_CPU 1000000UL

#include <util/delay.h>


#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#include "../lib/DIO_config.h"
#include "../lib/DIO_interface.h"
#include "../lib/DIO_private.h"




int main (void)
{

DIO_changePortDirection(PA, PORT_OUTPUT);

	for(;;)
	{
		for(char i=A0;i<=A7;i++)
		{			
			DIO_writePinState(i, HIGH);
			_delay_ms(500);
		}
		DIO_writePortState(PA, PORT_LOW);
		_delay_ms(500);
	}


	return 0;
}
