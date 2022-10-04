/*
Este c�digo visa reproduzir alguma m�sica.
NOTA: 					FREQU�NCIA(Hz):
D� 						261,63
Re 						293,66
Mi 						329,63
F� 						349,23
F�#                     369,99
Sol 					392
La 						440
Si 						493,88
*/

#include "main.h"

// Fun��o que contabiliza tempo.
void tempo (void) {
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
  TIM10->ARR=9;  // coloca 9 no ARR;
  GPIOA->MODER=0x28000001;  // configura a fun��o de Debugger com o ARM e o pino PA0 como sa�da;

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
	  // Nota "d�".
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
	  // Nota "d�".
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
	  // Nota "d�".
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
	  }// Nota "d�".
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
