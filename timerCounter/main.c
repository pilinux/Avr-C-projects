/**
	@author Mahir
	@version 0.1
	@file main.c
*/

// CPU clock for atmega8
#define F_CPU 3686400UL

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/


/**
	@brief Init the microcontroller
*/
void init(void){

	DDRB |= (1 << DDB0); 	// PB0 is the only output

}
/******************************************************************************/

/**
	@brief Main function
*/
int main(void){
	
	// Init
	init();
	
	TCCR1B |= (1 << CS11)|(1 << CS10); //prescaler 64
	TCNT1 = 0; //Timer count

	// Loop forever
	while (1){
		
		/* Task
		** f= 1Hz, so T= 1s = T(ON) + T(OFF); Toggle LED every 0.5s
		*/		
		
		if (TCNT1 >= 62499){
			PORTB ^= (1 << PB0);
			TCNT1 = 0;
		}
				
	}
	
	return 0;
}
/******************************************************************************/
