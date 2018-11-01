#include "waveGenerator.h"
#include "stm32l476xx.h"


void configInterupts(void)
{
	/*
	user TIM6 and TIM 7 to be the interrupts for the 
	
	*/
	NVIC_DisableIRQ(TIM2_IRQn);
	NVIC_EnableIRQ(TIM2_IRQn);
	NVIC_SetPriority(TIM2_IRQn, 1); // set the priority of the interrupt
	
	//set the timer settings using the TIM_TypeDef specifically the TIM2, TIM3 and TIM4

	NVIC_ClearingPending(TIM2_IRQn);// clear the pending flag every time the function is used
	
}