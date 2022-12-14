/*
 * Fazer um contador crescente/descrescente hexadecimal com dois dígitos.
 * Conta o número de vezes que foi pressionado dois botões.
 */

#include "main.h"

int display1 = 0, display2 = 0;  // contagem dos 2 displays;
int contador_display = 0;  // indica qual display estamos ligando;
int hexadecimal[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};  // números de 0 à 9 + A ao F;
int estado_atual1=0;
int estado_atual2=0;

void TIM1_UP_TIM10_IRQHandler(){
	// Se algum display passar do número 9 (índice do vetor "numeros[]"), o display volta à zero. Caso contrário, é acrescentado.
	// Os displays também funcionam de acordo com as regras das horas, minutos e segundos.

	TIM10->SR&=~(0x01);  // limpando flag do TIMER10;
}

int i = 801;

void TIM1_TRG_COM_TIM11_IRQHandler(){
	GPIOC->ODR|=0x3F00;  // desligando todos os displays (colocando o segmento comum deles no VCC);
	GPIOC->ODR&=~0xFF;  // limpando os oito bits (colocando zero nos segmentos dos displays);

	// Ajuste do display1 (botão contador).
	if(((GPIOA->IDR)&0x00000003) == 0x0001 && i>800 && estado_atual1 == 0){
		estado_atual1 = 1;
		i = 0;
		if(display2 == 15){
			display2 = 0;
			if(display1 == 15){
				display1 = 0;
			}
			else{
				display1++;
			}
		}
		else{
			display2++;
		}
	}
	else if(((GPIOA->IDR)&0x00000003) == 0x0000 && i>800 && estado_atual1 == 1){
		estado_atual1 = 0;
		i++;
	}
	else {
		i++;
	}

	// Ajuste do display2 (botão que decrementa).
	if(((GPIOA->IDR)&0x00000003) == 0x0002 && i>800 && estado_atual2 == 0){
		estado_atual2 = 1;
		i=0;
		if(display2 == 0){
			display2 = 15;
			if(display1 == 0){
				display1 = 15;
			}
			else{
				display1--;
			}
		}
		else{
			display2--;
		}
	}
	else if(((GPIOA->IDR)&0x00000003) == 0x0000 && i>800 && estado_atual2 == 1){
		estado_atual2 = 0;
		i++;
	}
	else {
		i++;
	}

	// Verifica qual display "está na sua vez" de ser acionado a partir do zero em seu segmento comum.
	switch(contador_display){
		case 0:
	        GPIOC->ODR|=hexadecimal[display1];
	        GPIOC->ODR&=~0x100;
	        break;
	    case 1:
	        GPIOC->ODR|=hexadecimal[display2];
	        GPIOC->ODR&=~0x200;
	        break;
	}

	// Verifica se o contador do display ultrapassou o número 1 e acresenta-se de acordo com essa informação.
	if(contador_display == 1) {
		contador_display = 0;
	}
	else {
		contador_display++;
	}

	TIM11->SR&=~(0x01);  // limpando flag do TIMER11;
}

void configuracao_timer_10(void) {
	// Configura o TIMER 10 para 1s.
	RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
	TIM10->CR1|=0x01;  // habilita a contagem do TIMER10;
	TIM10->PSC=3999;  // coloca 3999 no PSC;
	TIM10->ARR=3999;  // coloca 3999 no ARR;

	TIM10->DIER|=0x01;  // habilita interrupção do TIMER10;
	// Habilita interrupção no controlador:
	NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 3);  // Priority = 3;
	NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}

void configuracao_timer_11(void) {
	// Configura o TIMER 11 para 1ms.
	RCC->APB2ENR|=0x40000;  // inicializa o clock do TIMER11;
	TIM11->CR1|=0x01;  // habilita a contagem do TIMER11;
	TIM11->PSC=799;  // coloca 799 no PSC;
	TIM11->ARR=19;  // coloca 19 no ARR;

	TIM11->DIER|=0x01;  // habilita interrupção do TIMER11;
	// Habilita interrupção no controlador:
	NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, 4);  // Priority = 4;
	NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
}

int main(void)
{
	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
	GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM e os pinos PA0 e PA1 como entradas;
	GPIOC->MODER=0X05555555;  // configura o pino PC0 ao pino PC13 como saídas;
	configuracao_timer_10();  // configura o TIMER 10;
	configuracao_timer_11();  // configura o TIMER 11;
	while (1)
	{

	}
}
