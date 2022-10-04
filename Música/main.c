/*
Este código visa reproduzir alguma música.
NOTA: 					FREQUÊNCIA(Hz):
Dó 						261,63
Re 						293,66
Mi 						329,63
Fá 						349,23
Fá#                     369,99
Sol 					392
La 						440
Si 						493,88
*/

#include "main.h"

// Função que contabiliza tempo.
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
  TIM10->ARR=9;  // coloca 9 no ARR;
  GPIOA->MODER=0x28000001;  // configura a função de Debugger com o ARM e o pino PA0 como saída;

  while (1)
  {
	  // Nota "la".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=1815;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
	  	  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "fa#".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2159;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "la".
	  for(int i=0; i < 50; i++) {
	  	  TIM10->PSC=1815;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "fa#".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2159;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "la".
	  for(int i=0; i < 50; i++) {
	  	  TIM10->PSC=1815;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "mi".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2423;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "la".
	  for(int i=0; i < 50; i++) {
	  	  TIM10->PSC=1815;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "mi".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2423;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "la".
	  for(int i=0; i < 50; i++) {
	  	  TIM10->PSC=1815;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "re".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2727;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "fa#".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2159;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "fa#".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2159;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "dó".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=3055;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	   }
	  // Nota "la".
	  for(int i=0; i < 50; i++) {
	  	  TIM10->PSC=1815;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "dó".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=3055;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	   }
	  // Nota "re".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2727;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "mi".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2423;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "dó".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=3055;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	   }
	  // Nota "la".
	  for(int i=0; i < 50; i++) {
	  	  TIM10->PSC=1815;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }// Nota "dó".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=3055;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	   }
	  // Nota "re".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2727;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "mi".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2423;
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);
	  }
	  // Nota "sol".
	  for(int i=0; i < 50; i++) {
		  TIM10->PSC=2039;
	  	  tempo();
	  	  GPIOA->ODR|=0x00000001;
	  	  tempo();
	  	  GPIOA->ODR&=~(0x00000001);
	  }
  }
}
