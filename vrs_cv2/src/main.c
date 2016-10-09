

#include <stddef.h>
#include "stm32l1xx.h"

int main(void)
{






  int i=0;
  int pomocna=0;
  int counter=0;
  int counter2=0;
  int BUTTON=0;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);

  GPIOA->MODER |=((0b01)<<10);
  GPIOA->OTYPER &= ~((0b01)<<5);
  GPIOA->PUPDR |=((0b01)<<10);
  GPIOA->OSPEEDR |=((0b11)<<10);
  //GPIOA->ODR  ^=((uint16_t)(0b1)<<5);


  GPIOC->MODER &= ~((0b11)<<26);
  GPIOC->OTYPER &= ~((0b01)<<13);
  GPIOC->PUPDR &= ~((0b11)<<26);


/*
  	GPIO_InitTypeDef GPIO_InitStructure;
  	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
  	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
  	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_40MHz;
  	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);

  	GPIO_InitTypeDef GPIOC_InitStructure;
  	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);
  	GPIOC_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  	GPIOC_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIOC_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOC,&GPIOC_InitStructure);
  	*/

  void Delay(void){
      int i;
      for(i=0;i<50000;i++);
  }

  void Delay2(void){

      int i;
      for(i=0;i<100000;i++);
  }


  while (1)
  {
	  //------------------1 uloha------------------------//
	  //zapnutie LED ODR
	  //GPIOA->ODR |=((uint16_t)(0b1)<<5);
	  //GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  //vypnutie LED ODR
	  //GPIOA->ODR &= ~((uint16_t)(0b1)<<5);
	  //GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	  //zapnutie LED BSRR
	  //GPIOA->BSRRL |=((uint16_t)(0b1)<<5);
	  //vypnutie LED BSSR
	  //GPIOA->BSRRH |=((uint16_t)(0b1)<<5);
	  //toglovanie LED
	  //GPIOA->ODR^=((uint16_t)(0b1)<<5);

	  //----------------2 uloha------------------------//
	  //stav tlacidla pomocou premennej BUTTON
	  if( ((GPIOC->IDR)  & (uint16_t)(0b01<<13))==0){
		  BUTTON=1;
	  }
	  else BUTTON=0;

	  //-----------------------------------------------//
	  //stav tlacidla pomocou premennej BUTTON standartna kniznica
	  /*if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)==0){
		  BUTTON=1;
	  }
	  else BUTTON=0;
	  */

	  //---------------3 uloha-------------------------//
	  // blikanie LED vo vybranom intervale
	  /*if( ((GPIOC->IDR)  & (uint16_t)(0b01<<13))==0){
		    GPIOA->BSRRL |=((uint16_t)(0b1)<<5);
		    Delay();
		    GPIOA->BSRRH |=((uint16_t)(0b1)<<5);
		    Delay();

	  }
	  else {
		   GPIOA->BSRRL |=((uint16_t)(0b1)<<5);
		   Delay2();
		   GPIOA->BSRRH |=((uint16_t)(0b1)<<5);
		   Delay2();
	  }*/
	  //-------------------------------------------------------//
	  // blikanie LED vo vybranom intervale standartna kniznica
	  /*if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)==0){
		  GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  	  Delay();
	  	  GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	  	  Delay();
	  }
	  else {
		  GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  	  Delay2();
	  	  GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	  	  Delay2();
	  }*/
	  //--------------------------------------------------------//
	  // sledovanie stavu tlacidla
	  /*if( ((GPIOC->IDR)  & (uint16_t)(0b01<<13))==0){
	    	GPIOA->BSRRL |=((uint16_t)(0b1)<<5);
	  }
	  else GPIOA->BSRRH |=((uint16_t)(0b1)<<5);
	  */
	  //--------------------------------------------------------//
	  // sledovanie stavu tlacidla standartna kniznica
	  /*if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)==0){
		  GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  }
	  else GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	  */
	  //---------------------------------------------------------//
	  //on off LED

	/*if( ((GPIOC->IDR)  & (uint16_t)(0b01<<13))==0){
		counter++;
		if (counter>5){
			pomocna=1;
	  	  	counter=0;
	  	}
	}
	if (pomocna==1){
		if( ((GPIOC->IDR)  & (uint16_t)(0b01<<13))!=0){
			counter2++;
	  	    if (counter2>5){
	  	    	GPIOA->ODR^=((uint16_t)(0b1)<<5);
	  	  	 	pomocna=0;
	  	  	 	counter2 = 0;
	  	    }
	  	}
	}
	*/
	//------------------------------------------------------//
	// on off LED standartna kniznica

	 /* if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)==0){
			counter++;
			if (counter>5){
				pomocna=1;
		  	  	counter=0;
		  	}
		}
		if (pomocna==1){
			if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)!=0){
				counter2++;
		  	    if (counter2>5){
		  	    	GPIOA->ODR^=((uint16_t)(0b1)<<5);
		  	  	 	pomocna=0;
		  	  	 	counter2 = 0;
		  	    }
		  	}
		}
*/
		i++;

  }
  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  /*while (1)
  {
  }*/
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
 /* while(1)
  {}*/
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
