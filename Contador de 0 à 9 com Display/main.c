/*
Este código visa controlar um display catodo de sete segmentos.
Ele irá operar como um contador de 0 até 9.
*/

#include "main.h"

void tempo(void) {
	// aguarda 1 segundo.
	for(int i=0; i<1600000; i++);
}

void numero_0(void) {
	// liga os pinos: a (B1); b (B2); c (B3); d (B5); e (B12); f (B13).
	GPIOB->ODR=0x0000302E;
}

void numero_1(void) {
	// liga os pinos: b (B2); c (B3).
	GPIOB->ODR=0x0000000C;
}

void numero_2(void) {
	// liga os pinos: a (B1); b (B2); d (B5); e (B12); g (B14).
	GPIOB->ODR=0x00005026;
}

void numero_3(void) {
	// liga os pinos: a (B1); b (B2); c (B3); d (B5); g (B14).
	GPIOB->ODR=0x0000402E;
}

void numero_4(void) {
	// liga os pinos: b (B2); c (B3); f (B13); g (B14).
	GPIOB->ODR=0x0000600C;
}

void numero_5(void) {
	// liga os pinos: a (B1); c (B3); d (B5); f (B13); g (B14).
	GPIOB->ODR=0x0000602A;
}

void numero_6(void) {
	// liga os pinos: a (B1); c (B3); d (B5); e (B12); f (B13); g (B14).
	GPIOB->ODR=0x0000702A;
}

void numero_7(void) {
	// liga os pinos: a (B1); b (B2); c (B3).
	GPIOB->ODR=0x0000000E;
}

void numero_8(void) {
	// liga os pinos: a (B1); b (B2); c (B3); d (B5); e (B12); f (B13); g (B14).
	GPIOB->ODR=0x0000702E;
}

void numero_9(void) {
	// liga os pinos: a (B1); b (B2); c (B3); f (B13); g (B14).
	GPIOB->ODR=0x0000600E;
}

int main(void)
{
	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
    	GPIOA->MODER=0x28000000;  // inicializa o modo debugger para a interface do ARM;
	GPIOB->MODER=0x15000454;  // configura os pinos B1, B2, B3, B5, B12, B13, B14 com a função de saída;
	// pino a - pino B1;	pino b - pino B2;	pino c - pino B3; pino d - pino B5;
	// pino e - pino B12; pino f - pino B13;	pino g - pino B14

	while (1)
	{
		numero_0();
		tempo();
		numero_1();
		tempo();
		numero_2();
		tempo();
		numero_3();
		tempo();
		numero_4();
		tempo();
		numero_5();
		tempo();
		numero_6();
		tempo();
		numero_7();
		tempo();
		numero_8();
		tempo();
		numero_9();
		tempo();
	}
}
