/*
Este código visa gerar os 7 tons maiores.
NOTA: 					FREQUÊNCIA(Hz):
Dó 						261,63
Re 						293,66
Mi 						329,63
Fá 						349,23
Sol 					392
La 						440
Si 						493,88
*/

#include "main.h"

int nota = 0;

// Função que contabiliza tempo.
void tempo (void) {
	while((TIM10->SR & 0x0001) == 0x0000) {  // verifica se o cronômetro foi "setado" (acabou a contagem);
		// enquanto o cronômetro não for "setado para 1", a contagem irá continuar dentro desse while;
	}
	TIM10->SR&=~(0x0001);  // "resetar" o cronômetro, botando zero no bit em questão;
	if((GPIOC->IDR & 0x000007F) == 0x00000001) {
		nota = 1;
	}
	else if((GPIOC->IDR & 0x0000007F) == 0x00000002) {
		nota = 2;
	}
	else if((GPIOC->IDR & 0x0000007F) == 0x00000004) {
		nota = 3;
	}
	else if((GPIOC->IDR & 0x0000007F) == 0x00000008) {
		nota = 4;
	}
	else if((GPIOC->IDR & 0x0000007F) == 0x00000010) {
		nota = 5;
	}
	else if((GPIOC->IDR & 0x0000007F) == 0x00000020) {
		nota = 6;
	}
	else if((GPIOC->IDR & 0x0000007F) == 0x00000040) {
		nota = 7;
	}
	else {
		nota = 0;
	}
}

int main(void) {
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  TIM10->ARR=9;  // coloca 9 no ARR;
  GPIOA->MODER=0x28000001;  // configura a função de Debugger com o ARM e o pino PA0 como saída;
  GPIOC->MODER=0x00000000;  // configura os pinos PC0, PC1, PC2, PC3, PC4, PC5 e PC6 como entradas;

  while (1) {
	  if(nota == 1) {
		  TIM10->PSC=3055;
	  }
	  else if(nota == 2) {
		  TIM10->PSC=2727;
	  }
	  else if(nota == 3) {
		  TIM10->PSC=2423;
	  }
	  else if(nota == 4) {
		  TIM10->PSC=2287;
	  }
	  else if(nota == 5) {
		  TIM10->PSC=2039;
	  }
	  else if(nota == 6) {
		  TIM10->PSC=1815;
	  }
	  else if(nota == 7) {
		  TIM10->PSC=1615;
	  }
	  if(nota != 0) {
		  tempo();
		  GPIOA->ODR|=0x00000001;
		  tempo();
		  GPIOA->ODR&=~(0x00000001);

	  }
	  if(nota == 0) {
		  tempo();
	  }
  }
}
