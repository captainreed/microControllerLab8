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

void adcinit()
{
	RCC->CR |= RCC_CR_HSION;
	while(RCC->CR & RCC_CR_HSIRDY == 0)
	{
		(void)0;
	}
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN;
	RCC->AHB2ENR |= RCC_AHB2ENR_ADCEN;
	
	GPIOA->MODER |= GPIO_MODER_MODE0_0;
	GPIOA->MODER |= GPIO_MODER_MODE0_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR0_0;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR0_1;
	GPIOA->ASCR  |= GPIO_ASCR_EN_0;
	
	ADC->CR &= ~ADC_CR_ADEN;
	//continue to follow psuedocode on textbook page 498
	//step 3
}

void readadc()
{
	return ADC_DR;
}
