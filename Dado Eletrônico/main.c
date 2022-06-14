#include "main.h"
#include <stdio.h>
#include <time.h>

int numero = 0;

void num_1(void) {
	// liga o pino MEIO - centro (PB5);
	GPIOB->ODR=0x00000020;
}

void num_2(void) {
	// liga os pinos:
	// SUPERIOR - esquerda (PB1) e INFERIOR - direita (PB14);
	GPIOB->ODR=0x00004002;
}

void num_3(void) {
	// liga os pinos:
	// SUPERIOR - esquerda (PB1), MEIO - centro (PB5) e INFERIOR - direita (PB14);
	GPIOB->ODR=0x00004022;
}

void num_4(void) {
	// liga os pinos:
	// SUPERIOR - esquerda (PB1) e direita (PB3);
	// INFERIOR - esquerda (PB12) e direita (PB14);
	GPIOB->ODR=0x0000500A;
}

void num_5(void) {
	// liga os pinos:
	// SUPERIOR - esquerda (PB1) e direita (PB3);
	// MEIO - centro (PB5);
	// INFERIOR - esquerda (PB12) e direita (PB14);
	GPIOB->ODR=0x0000502A;
}

void num_6(void) {
	// liga os pinos:
	// SUPERIOR - esquerda (PB1), centro (PB2) e direita (PB3);
	// INFERIOR - esquerda (PB12), centro (PB13) e direita (PB14);
	GPIOB->ODR=0x0000700E;
}

int estado_atual = 0;

void teste(void) {
	for(int i=0; i!=16000; i++);
	if ((estado_atual == 0) && ((GPIOB->IDR & 0x00008000) != 0x0)) {
		estado_atual = 1;
		numero = rand() % 7;
	}

	if ((estado_atual == 1) && ((GPIOB->IDR&0x00008000) == 0x0)){
		estado_atual = 0;
	}
}

int main(void)
{
	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
    GPIOA->MODER=0x28000000;  // inicializa o modo debugger para a interface do ARM;
    GPIOB->MODER=0x15000454;  // configura os pinos B1, B2, B3, B5, B12, B13, B14 com a função de saída;
	// SUPERIOR: esquerda - PB1; centro - PB2; direita - PB3.
	// MEIO: centro - PB5.
	// INFERIOR: esquerda - PB12; centro - PB13; direita - PB14.
	// Pino PB15 - botão.

	srand(time(NULL));

	while (numero == 0) {
		numero = rand() % 7;
	}

	while (1)
	{
		teste();

		if (numero == 0) {
			while (numero == 0) {
				numero = rand() % 7;
			}
		}
		else if(numero == 1) {
			num_1();
		}
		else if(numero == 2) {
			num_2();
		}
		else if(numero == 3) {
			num_3();
		}
		else if(numero == 4) {
			num_4();
		}
		else if(numero == 5) {
			num_5();
		}
		else if(numero == 6) {
			num_6();
		}
	}
}
