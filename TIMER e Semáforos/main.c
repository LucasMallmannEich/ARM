/*
Este c�digo visa controlar dois conjuntos de 3 LEDs.
LEDs: Vermelho, Verde e Amarelo (simulando um sem�foro).
*/

#include "main.h"

// Fun��o que contabiliza tempo.
void tempo () {
	while((TIM10->SR & 0x0001) == 0x0000) {  // verifica se o cron�metro foi "setado" (acabou a contagem);
		// enquanto o cron�metro n�o for "setado para 1", a contagem ir� continuar dentro desse while;
	}
	TIM10->SR&=~(0x0001);  // "resetar" o cron�metro, botando zero no bit em quest�o;
}

int main(void) {
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  TIM10->PSC=15999;  // coloca 15999 no PSC;
  TIM10->ARR=699;  // coloca 699 no ARR;
  GPIOA->MODER=0x28000000;  // configura a fun��o de Debugger com o ARM;
  GPIOC->MODER=0x00000555;  // configura os pinos PC0 (verde), PC1 (amarelo), PC2 (vermelho), PC3, PC4 e PC5 como sa�da;
    
  while (1) {
	  GPIOC->ODR|=0x00000009;  // acende os pinos verdes (PC0 e PC3);
	  tempo();  // espera 700 ms;
	  GPIOC->ODR|=0x00000012;  // acende os pinos amarelos (PC1 e PC4);
	  TIM10->ARR=199;  // coloca 199 no ARR;
	  tempo();  // espera 200 ms;
	  GPIOC->ODR&=~(0x0000001B);  // apaga os pinos verdes e amarelos (PC0, PC1, PC3 e PC4);
	  TIM10->ARR=699;  // coloca 699 no ARR;
	  GPIOC->ODR|=0x00000024;  // acende os pinos vermelhos (PC2 e PC5);
	  tempo();  // espera 700 ms;
	  GPIOC->ODR&=~(0x00000024);  // apaga os pinos vermelhos (PC2 e PC5);
  }
}
