/*
 * Este c�digo visa simular um rel�gio digital (horas, minutos e segundos).
 * O programa utiliza 2 bot�es para incrementar a hora e o minuto.
 * O hor�rio N�O fica rodando, a partir do conceito de multiplexa��o (MUX).
 */

#include "main.h"

// DISPLAY1 - H1, DISPLAY2 - H2, DISPLAY3 - M1, DISPLAY4 - M2, DISPLAY5 - S1, DISPLAY6 - S2
int display1 = 0, display2 = 0, display3 = 0, display4 = 0, display5 = 0, display6 = 0;  // contagem dos 6 displays;
int contador_display = 0;  // indica qual display estamos ligando;
int numeros[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};  // n�meros de 0 � 9;

void TIM1_UP_TIM10_IRQHandler(){
	// Se algum display passar do n�mero 9 (�ndice do vetor "numeros[]"), o display volta � zero. Caso contr�rio, � acrescentado.
	// Os displays tamb�m funcionam de acordo com as regras das horas, minutos e segundos.
	if(display6 == 9){
		display6 = 0;
		if(display5 == 5){
			display5 = 0;
			if(display4 == 9){
				display4 = 0;
				if(display3 == 5){
					display3 = 0;
					if(display2 == 9){
						display2 = 0;
						display1++;
					}
					else if(display2 == 3 && display1 == 2){
						display2 = 0;
						display1 = 0;
					}
					else{
						display2++;
					}
				}
				else{
					display3++;
				}
			}
			else{
				display4++;
			}
		}
		else{
			display5++;
		}
	}
	else {
		display6++;
	}

	TIM10->SR&=~(0x01);  // limpando flag do TIMER10;
}

void TIM1_TRG_COM_TIM11_IRQHandler(){
	GPIOC->ODR|=0x3F00;  // desligando todos os displays (colocando o segmento comum deles no VCC);
	GPIOC->ODR&=~0xFF;  // limpando os oito bits (colocando zero nos segmentos dos displays);

	// Verifica qual display "est� na sua vez" de ser acionado a partir do zero em seu segmento comum.
	switch(contador_display){
		case 0:
	        GPIOC->ODR|=numeros[display1];
	        GPIOC->ODR&=~0x100;
	        break;
	    case 1:
	        GPIOC->ODR|=numeros[display2];
	        GPIOC->ODR&=~0x200;
	        break;
	    case 2:
	    	GPIOC->ODR|=numeros[display3];
	        GPIOC->ODR&=~0x400;
	        break;
	    case 3:
	    	GPIOC->ODR|=numeros[display4];
	        GPIOC->ODR&=~0x800;
	        break;
	    case 4:
	    	GPIOC->ODR|=numeros[display5];
	    	GPIOC->ODR&=~0x1000;
	    	break;
	    case 5:
	    	GPIOC->ODR|=numeros[display6];
	    	GPIOC->ODR&=~0x2000;
	    	break;
	}

	// Verifica se o contador do display ultrapassou o n�mero 5 e acresenta-se de acordo com essa informa��o.
	if(contador_display == 5) {
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

	TIM10->DIER|=0x01;  // habilita interrup��o do TIMER10;
	// Habilita interrup��o no controlador:
	NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 3);  // Priority = 3;
	NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}

void configuracao_timer_11(void) {
	// Configura o TIMER 11 para 1ms.
	RCC->APB2ENR|=0x40000;  // inicializa o clock do TIMER11;
	TIM11->CR1|=0x01;  // habilita a contagem do TIMER11;
	TIM11->PSC=799;  // coloca 799 no PSC;
	TIM11->ARR=19;  // coloca 19 no ARR;

	TIM11->DIER|=0x01;  // habilita interrup��o do TIMER11;
	// Habilita interrup��o no controlador:
	NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, 4);  // Priority = 4;
	NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
}

int main(void)
{
	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
	GPIOA->MODER=0x28000000;  // configura a fun��o de Debugger com o ARM;
	GPIOC->MODER=0X05555555;  // configura o pino PC0 ao pino PC13 como sa�das;
	configuracao_timer_10();  // configura o TIMER 10;
	configuracao_timer_11();  // configura o TIMER 11;
	while (1)
	{

	}
}
