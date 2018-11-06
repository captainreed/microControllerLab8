#include "readDAC.h"

void DACinit()
{
  RCC->APB1ENR1 |= RCC_APB1ENR1_DAC1EN;// turn on dac clock
  DAC->CR&= ~( DAC_CR_EN1 | DAC_CR_EN2);// turn off dac so you can alter registers
  DAC->MCR &= ~( DAC_MCR_MODE2_0 | DAC_MCR_MODE2_1 | DAC_MCR_MODE2_2 ); // clear channel 2 register
  DAC->MCR |=  ~DAC_MCR_MODE2_0 | ~DAC_MCR_MODE2_1 | ~DAC_MCR_MODE2_2; // mode0 000 is external pin buffered 
    //mode1 010 is external pin not buffered
    //mode2 100 is external pin buffered with sample and hold
    //mode3 110 is external pin not buffered with sample and hold
    //book recommends mode0 i see potential for the other 3 modes and there are others beyond these 4
  DAC->CR |= DAC_CR_TEN2; //enable trigger for channel 2
  DAC->CR &= ~( DAC_CR_TSEL2_0 | DAC_CR_TSEL2_1 | DAC_CR_TSEL2_2);// clear trigger selection
  DAC->CR |= DAC_CR_TSEL2_0;
  DAC->CR |= DAC_CR_TSEL2_2; // select TIM4_TRGO
  // init pin A5 might not need the pin but just in case
  //RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;//enable port A clock
  //set to analog mode pin A5
  //GPIOA-> MODER |= GPIO_MODER_MODER5_0;
  //GPIOA-> MODER |= GPIO_MODER_MODER5_1;
  //end pin init
  //this block is the timer 4 init
  RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN;
  TIM4->CR1 &= ~TIM_CR1_DIR;//up counting
  TIM4->PSC = 3999;
  TIM4->ARR = 999;
  TIM4->CCR1 = 998;
  //set the CC1S in the CCMR1 to output if it is not already so (reset value should have it as output already)
  TIM4->DIER |= TIM_DIER_TIE;
  //end timer init
  //enable the DAC
  DAC->CR |= DAC_CR_EN2;
}

void readDAC()
{
  //DAC->CR &= ~DAC_CR_EN2;
  //deactivate timer
  TIM4->CR1 &= ~TIM_CR_CEN;
  TIM4->ARR = ?????;//not sure where to grab this value from or if it is given
  TIM4->CR1 |= TIM_CR_CEN;
 }
