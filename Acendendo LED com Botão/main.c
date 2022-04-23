#include "main.h"

int main(void) {

	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
	GPIOA->MODER=0x28000400;  // inicializa o modo debugger para a interface do ARM, colocando o pino A5 como saída;
	GPIOC->MODER=0x00000000;  // inicializa os pinos da porta C como entradas;

	while (1) {
		if (((GPIOC->IDR)&0x00002000) == 0x0) {  // testa se o o pino da posição 13 é nível lógico baixo;
			GPIOA->ODR|=0x00000020;  // coloca o pino A5 no nível lógico alto;
		}
		else {
			GPIOA->ODR&=0xFFFFFFDF;  // coloca o pino A5 no nível lógico baixo;
		}
	}
}
