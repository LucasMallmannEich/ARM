#include "main.h"

// Função que contabiliza tempo (100ms).
void tempo (void) {
	while((TIM10->SR & 0x0001) == 0x0000) {  // verifica se o cronômetro foi "setado" (acabou a contagem);
		// enquanto o cronômetro não for "setado para 1", a contagem irá continuar dentro desse while;
	}
	TIM10->SR&=~(0x0001);  // "resetar" o cronômetro, botando zero no bit em questão;
}

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
  TIM10->PSC=999;  // coloca 999 no PSC;
  TIM10->ARR=1599;  // coloca 1599 no ARR;
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  GPIOA->MODER=0x28010000;  // configura a função de Debugger com o ARM e configura o pino PA8 como saída;
  GPIOB->MODER=0X00000000;  // configura os pinos PB3, PB4 e PB5 como entradas;

  while (1) {
	  if ((GPIOB->IDR & 0x00000038) == 0x00000000) {  // caso nenhum pino esteja em "1";
		  GPIOA->ODR|=0x00000100;  // acende o pino 8;
	  }

	  else if ((GPIOB->IDR & 0x00000038) == 0x00000008) {  // caso o pino PB3 esteja em "1";
		  GPIOA->ODR|=0x00000100;  // liga o PA8;
		  tempo();
		  GPIOA->ODR&=~(0x00000100);  // desliga o PA8;
		  tempo();
		  for (int j=0; j < 8; j++) {
			  tempo();
		  }
	  }

	  else if ((GPIOB->IDR & 0x00000038) == 0x00000010) {  // caso o pino PB4 esteja em "1";
		  for (int i=0; i < 2; i++) {
			 GPIOA->ODR|=0x00000100;  // liga o PA8;
			 tempo();
			 GPIOA->ODR&=~(0x00000100);  // desliga o PA8;
			 tempo();
		  }
		  for (int j=0; j < 6; j++) {
			  tempo();
		  }
	  }

	  else if ((GPIOB->IDR & 0x00000038) == 0x00000018) {  // caso o pino PB3 e PB4 estejam em "1";
		  for (int i=0; i < 3; i++) {
			  GPIOA->ODR|=0x00000100;  // liga o PA8;
			  tempo();
			  GPIOA->ODR&=~(0x00000100);  // desliga o PA8;
			  tempo();
		  }
		  for (int j=0; j < 4; j++) {
			  tempo();
		  }
	  }

	  else if ((GPIOB->IDR & 0x00000038) == 0x00000020) {  // caso o pino PB5 esteja em "1";
		  for (int i=0; i < 4; i++) {
			  GPIOA->ODR|=0x00000100;  // liga o PA8;
			  tempo();
			  GPIOA->ODR&=~(0x00000100);  // desliga o PA8;
			  tempo();
		  }
		  for (int j=0; j < 2; j++) {
			  tempo();
		  }
	  }

	  else if ((GPIOB->IDR & 0x00000038) == 0x00000028) {  // caso o pino PB5 e o pino PB estejam em "1";
		  for (int i=0; i < 5; i++) {
			  GPIOA->ODR|=0x00000100;  // liga o PA8;
			  tempo();
			  GPIOA->ODR&=~(0x00000100); // desliga o PA8;
			  tempo();
		  }
	  }

	  for (int i=0; i < 10; i++) {
		  tempo();
	  }
  }
}
