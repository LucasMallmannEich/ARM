/*
	Este c�digo visa funcionar de tal maneira que, quando o bot�o do ARM (pino PC13) for pressionado,
a sequ�ncia de acionamento dos LEDs ser� alternada.
*/

#include "main.h"

int x=0;

void tempo (void) {
	for (int i=0; i != 160000; i++) {  // espera 0,1 segundo;
		if (((GPIOC->IDR)&0x00002000) == 0x0) {  // testa se o pino da posi��o 13 � n�vel l�gico baixo;
			if (x == 0) {
				x = 1;
			}
			else {
				x = 0;
			}
			teste();
		}
	}
}

void teste (void) {
	if (x == 0) {
		sequencia_1();
	}
	else {
		sequencia_2();
	}
}

void sequencia_1(void) {
	GPIOB->ODR=0x00000002;  // liga o pino 1;
	GPIOB->ODR=0x00008000;  // liga o pino 15;
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

void sequencia_2(void) {
	GPIOB->ODR=0x00000002;  // liga o pino 1;
	tempo();  // espera 1 segundo;
	GPIOB->ODR|=0x00000004;  // liga o pino 2;
	tempo();  // espera 1 segundo;
	GPIOB->ODR|=0x00000008;  // liga o pino 3;
	tempo();  // espera 1 segundo;
	GPIOB->ODR|=0x00000020;  // liga o pino 5;
	tempo();  // espera 1 segundo;
	GPIOB->ODR|=0x00001000;  // liga o pino 12;
	tempo();  // espera 1 segundo;
	GPIOB->ODR|=0x00002000;  // liga o pino 13;
	tempo();  // espera 1 segundo;
	GPIOB->ODR|=0x00004000;  // liga o pino 14;
	tempo();  // espera 1 segundo;
	GPIOB->ODR|=0x00008000;  // liga o pino 15;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFF7FFF;  // desliga o pino 15;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFFBFFF;  // desliga o pino 14;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFFDFFF;  // desliga o pino 13;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFFEFFF;  // desliga o pino 12;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFFFFDF;  // desliga o pino 5;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFFFFF7;  // desliga o pino 3;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFFFFFB;  // desliga o pino 2;
	tempo();  // espera 1 segundo;
	GPIOB->ODR&=0xFFFFFFFD;  // desliga o pino 1;
	tempo();  // espera 1 segundo;
}

int main(void)
{
	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
	GPIOA->MODER=0x28000000;  // inicializa o modo debugger para a interface do ARM;
	GPIOB->MODER=0x55000454;  // configura os pinos B1, B2, B3, B5, B12, B13, B14 e B15 com a fun��o de sa�da;

	while (1)
	{
	  sequencia_1();
	}
}
