#include "main.h"

int estado_atual = 0;

// Função que contabiliza tempo (200ms).
void tempo (void) {
	while((TIM10->SR & 0x0001) == 0x0000) {  // verifica se o cronômetro foi "setado" (acabou a contagem);
		// enquanto o cronômetro não for "setado para 1", a contagem irá continuar dentro desse while;
		if((GPIOB->IDR & 0x0001) == 0x0000) {
			estado_atual = 0;  // atualiza a variável "estado_atual";
		}
	}
	TIM10->SR&=~(0x0001);  // "resetar" o cronômetro, botando zero no bit em questão;
}

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
  TIM10->PSC=99;  // coloca 99 no PSC;
  TIM10->ARR=31999;  // coloca 31999 no ARR;
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
  GPIOB->MODER=0X00000000;  // configura o pino PB3 como entrada;
  GPIOC->MODER=0x00000001;  // configura o pino PC0 como saída;


  while (1)
  {
    if(((GPIOB->IDR & 0x0001) == 0x0001) && estado_atual == 0) {
    	estado_atual=1;
    	for(int i=0; i < 13; i++) {
    		GPIOC->ODR|=0x00000001;  // acende o LED;
			tempo();  // espera 200ms;
			GPIOC->ODR&=~(0x00000001);  // apaga o LED;
			tempo();  // espera 200ms;
    	}
    	for(int i=0; i < 10; i++) {
    		tempo();  // espera 200 ms;
    	}
    	for(int i=0; i < 13; i++) {
			GPIOC->ODR|=0x00000001;  // acende o LED;
			tempo();  // espera 200ms;
			GPIOC->ODR&=~(0x00000001);  // apaga o LED;
			tempo();  // espera 200ms;
		}
    }
    else {
    	GPIOC->ODR&=~(0x00000001);  // desliga o LED;
    }
    if(((GPIOB->IDR & 0x0001) == 0x0000) && estado_atual == 1) {
    	estado_atual = 0;  // atualiza a variável "estado_atual";
    }
   }
}
