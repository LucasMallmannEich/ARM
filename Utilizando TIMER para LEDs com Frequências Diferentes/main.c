#include "main.h"

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  RCC->APB2ENR|=0x60000;  // inicializa o clock do TIMER10 e do TIMER11;
  TIM10->PSC=99;  // coloca 99 no PSC;
  TIM10->ARR=31999;  // coloca 31999 no ARR;
  TIM11->PSC=99;  // coloca 99 no PSC;
  TIM11->ARR=13332;  // coloca 13332 no ARR;
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  TIM11->CR1|=0x0005;  // habilita a contagem do TIMER11;
  GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
  GPIOB->MODER=0X00000000;  // configura o pino PB0 como entrada;
  GPIOC->MODER=0x00000005;  // configura o pino PC0 e o pino PC1 como saídas;

  while (1)
  {
	  if(((TIM10->SR & 0x0001) == 0x0001) && ((GPIOB->IDR & 0x0001) == 0x0000)) {  // verifica se o cronômetro foi "setado" (acabou a contagem);
		  TIM10->SR&=~(0x0001);  // "resetar" o cronômetro, botando zero no bit em questão;
		  if((GPIOC->IDR & 0x00000001) == 0x00000000) {  // verifica se o LED do pino PC0 está desligado;
			  GPIOC->ODR|=0x00000001;  // acende o LED do pino PC0;
		  }
		  else {
			  GPIOC->ODR&=~(0x00000001);  // desliga o LED do pino PC0;
		  }
	  }
	  if(((TIM11->SR & 0x0001) == 0x0001) && ((GPIOB->IDR & 0x0001) == 0x0000)) {  // verifica se o cronômetro foi "setado" (acabou a contagem);
		  TIM11->SR&=~(0x0001);  // "resetar" o cronômetro, botando zero no bit em questão;
		  if((GPIOC->IDR & 0x00000002) == 0x00000000) {  // verifica se o LED do pino PC1 está desligado;
		  	  GPIOC->ODR|=0x00000002;  // acende o LED do pino PC1;
		   }
		  else {
			  GPIOC->ODR&=~(0x00000002);  // desliga o LED do pino PC1;
		   }
	  }
  }
}
