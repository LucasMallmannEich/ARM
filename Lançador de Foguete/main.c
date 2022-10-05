#include "main.h"

int desparo = 0;

// Função que contabiliza tempo.
void tempo () {
	while((TIM10->SR & 0x0001) == 0x0000) {  // verifica se o cronômetro foi "setado" (acabou a contagem);
		// enquanto o cronômetro não for "setado para 1", a contagem irá continuar dentro desse while;
		if((GPIOC->IDR & 0x00000100) == 0x00000100) {
			desparo = 1;
		}
		if((GPIOC->IDR & 0x00000200) == 0x00000200) {
			while(1) {
				// encerra o programa;
			}
		}
	}
	TIM10->SR&=~(0x0001);  // "resetar" o cronômetro, botando zero no bit em questão;
}

int main(void)
{
	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
	RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
	TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
	TIM10->PSC=332;  // coloca 332 no PSC;
	TIM10->ARR=8007;  // coloca 8007 no ARR;
	GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
	GPIOC->MODER=0x00005555;  // configura os 8 primeiros pinos (PC0 ao PC7) como saídas e os pinos PC8 e PC9 como entradas;

	while (desparo == 0) {
		GPIOC->ODR|=0x0000007F;  // ligam os 7 primeiros LEDs;
		tempo();  //espera 0.333 segundos;
		GPIOC->ODR&=~(0x0000007F);  // desligam os 7 primeiros LEDs;
		tempo();  // espera 0.333 segundos;
	}

	GPIOC->ODR|=0x0000007F;  // liga todos os LEDs;
	TIM10->PSC=1997;  // coloca 1997 no PSC;

	tempo();  // espera 1 segundo;
	GPIOC->ODR&=~(0x00000001);  // desliga o LED1;
	tempo();  // espera 1 segundo;
	GPIOC->ODR&=~(0x00000002);  // desliga o LED2;
	tempo();  // espera 1 segundo;
	GPIOC->ODR&=~(0x00000004);  // desliga o LED3;
	tempo();  // espera 1 segundo;
	GPIOC->ODR&=~(0x00000008);  // desliga o LED4;
	tempo();  // espera 1 segundo;
	GPIOC->ODR&=~(0x00000010);  // desliga o LED5;
	tempo();  // espera 1 segundo;
	GPIOC->ODR&=~(0x00000020);  // desliga o LED6;
	tempo();  // espera 1 segundo;
	GPIOC->ODR&=~(0x00000040);  // desliga o LED7;
	tempo();  // espera 1 segundo;

	TIM10->PSC=1000;  // coloca 1000 no PSC;

	GPIOC->ODR|=0x00000080;  // liga o LED8;

	tempo();  // espera 3 segundos;
	tempo();
	tempo();

	GPIOC->ODR&=~(0x00000080);  // desliga o LED8;
}
