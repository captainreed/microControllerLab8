#include "PiezoBuzzer.h"
#include "stm32l476xx.h"

//new files:
//readADC.c
//waveGenerator.c this is where the interrupts will be initiated


//interupt 1
/*
set the interupt to be triggered every 2 ms
read the value every trigger period and store it into memory
*/

//interupt 2
/*
configure to be triggered every 500 ms
read the value from the ADC memory
newFreq = math.floor(100 + 900*(adcValue/maxADCValue))
call setFreq(newFreq)
*/



int main(void){
	
	initBuzzer();
//pseudo code****************
/*
configure a timer interrupt to trigger the ADC read function and write to memory
in wavegenerator.c write an array with 40 entries that are samples from a sin wave

configure another timer that triggers the setFreq() function in waveGenerator.c every 500ms
the frequency can be between 100 and 1000HZ
the setFreq(freq in HZ) function changes the time constant

*/

	while(1)
	{

	}
	
	
	
}
