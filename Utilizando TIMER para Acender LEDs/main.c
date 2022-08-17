#include "main.h"

// Função que contabiliza 100 ms.
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
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  TIM10->PSC=99;  // coloca o PSC para 99;
  TIM10->ARR=15999;  // coloca o ARR para 15999;
  GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
  GPIOB->MODER=0x55000454;  // configura os pinos B1, B2, B3, B5, B12, B13, B14 e B15 com a função de saída;

  while (1) {
	GPIOB->ODR|=0x00000002;  // liga o pino 1;
	GPIOB->ODR|=0x00008000;  // liga o pino 15;
	tempo();  // espera 100 ms;
	GPIOB->ODR|=0x00000004;  // liga o pino 2;
	GPIOB->ODR|=0x00004000;  // liga o pino 14;
	tempo();  // espera 100 ms;
	GPIOB->ODR|=0x00000008;  // liga o pino 3;
	GPIOB->ODR|=0x00002000;  // liga o pino 13;
	tempo();  // espera 100 ms;
	GPIOB->ODR|=0x00000020;  // liga o pino 5;
	GPIOB->ODR|=0x00001000;  // liga o pino 12;
	tempo();  // espera 100 ms;
	GPIOB->ODR&=0xFFFFFFDF;  // desliga o pino 5;
	GPIOB->ODR&=0xFFFFEFFF;  // desliga o pino 12;
	tempo();  // espera 100 ms;
	GPIOB->ODR&=0xFFFFFFF7;  // desliga o pino 3;
	GPIOB->ODR&=0xFFFFDFFF;  // desliga o pino 13;
	tempo();  // espera 100 ms;
	GPIOB->ODR&=0xFFFFFFFB;  // desliga o pino 2;
	GPIOB->ODR&=0xFFFFBFFF;  // desliga o pino 14;
	tempo();  // espera 100 ms;
	GPIOB->ODR&=0xFFFFFFFD;  // desliga o pino 1;
	GPIOB->ODR&=0xFFFF7FFF;  // desliga o pino 15;
	tempo();  // espera 100 ms;
  	}
}
