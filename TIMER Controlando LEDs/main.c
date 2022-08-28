#include "main.h"

// Fun��o que contabiliza tempo (250ms ou 71,13ms).
void tempo (void) {
	if((GPIOC->IDR&=0x00000002) == 0x00000000) {
		TIM10->PSC=6999;
		TIM10->ARR=162;
	}
	else {
		TIM10->PSC=3999;
		TIM10->ARR=999;
	}
	while((TIM10->SR & 0x0001) == 0x0000) {  // verifica se o cron�metro foi "setado" (acabou a contagem);
		// enquanto o cron�metro n�o for "setado para 1", a contagem ir� continuar dentro desse while;
	}
	TIM10->SR&=~(0x0001);  // "resetar" o cron�metro, botando zero no bit em quest�o;
}


int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  GPIOA->MODER=0x28000000;  // configura a fun��o de Debugger com o ARM;
  GPIOC->MODER=0X00000001;  // configura o pino PC0 como sa�da e PC1 como entrada;

  while (1) {
	  GPIOC->ODR|=0x00000001;  // liga o PC0;
	  tempo();
	  GPIOC->ODR&=~(0x00000001);  // desliga o PC0;
	  tempo();
  }
}
