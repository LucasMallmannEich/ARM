/*
 * Este código visa fazer um nome ficar rodando num conjunto de 4 displays de 7 segmentos cátodo comum.
 * Os pinos PC0 ao PC7 indicam o controle dos segmentos (que são curto circuitados entre os displays).
 * O pino PC8, PC9, PC10 e PC11 indicam, respectivamente, o segmento comum de cada display cátodo comum.
 * Ou seja, quando o PC8 estiver no GND (0), e o PC9, PC10 e PC11 estiverem no VCC (3.3), apenas o display 1 irá acender.
 */

#include "main.h"

int display1 = 0, display2 = 1, display3 = 2, display4 = 3;  // contagem dos 4 displays;
int contador_display = 0;  // indica qual display estamos ligando;
int letras[] = {0x38, 0x1C, 0x58, 0x77, 0x6D, 0x00};  // letras "L", "U", "C", "A", "S" e " " (espaço vazio);

void TIM1_UP_TIM10_IRQHandler(){
	// Se algum display passar do número 5 (índice do vetor "letras[]"), o display volta à zero. Caso contrário, é acrescentado.
	if(display1 == 5) {
		display1 = 0;
	}
	else {
		display1++;
	}
	if(display2 == 5) {
		display2 = 0;
	}
	else {
		display2++;
	}
	if(display3 == 5) {
		display3 = 0;
	}
	else {
		display3++;
	}
	if(display4 == 5) {
		display4 = 0;
	}
	else {
		display4++;
	}

	TIM10->SR&=~(0x01);  // limpando flag do TIMER10;
}

void TIM1_TRG_COM_TIM11_IRQHandler(){
	GPIOC->ODR|=0xF00;  // desligando todos os displays (colocando o segmento comum deles no VCC);
	GPIOC->ODR&=~0xFF;  // limpando os oito bits (colocando zero nos segmentos dos displays);

	// Verifica qual display "está na sua vez" de ser acionado a partir do zero em seu segmento comum.
	switch(contador_display){
		case 0:
	        GPIOC->ODR|=letras[display1];
	        GPIOC->ODR&=~0x100;
	        break;
	    case 1:
	        GPIOC->ODR|=letras[display2];
	        GPIOC->ODR&=~0x200;
	        break;
	    case 2:
	    	GPIOC->ODR|=letras[display3];
	        GPIOC->ODR&=~0x400;
	        break;
	    case 3:
	    	GPIOC->ODR|=letras[display4];
	        GPIOC->ODR&=~0x800;
	        break;
	}

	// Verifica se o contador do display ultrapassou o número 3 e acresenta-se de acordo com essa informação.
	if(contador_display == 3) {
		contador_display = 0;
	}
	else {
		contador_display++;
	}

	TIM11->SR&=~(0x01);  // limpando flag do TIMER11;
}

void configuracao_timer_10(void) {
	// Configura o TIMER 10 para 2s.
	RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
	TIM10->CR1|=0x01;  // habilita a contagem do TIMER10;
	TIM10->PSC=7999;  // coloca 7999 no PSC;
	TIM10->ARR=3999;  // coloca 3999 no ARR;

	TIM10->DIER|=0x01;  // habilita interrupção do TIMER10;
	// Habilita interrupção no controlador:
	NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 3);  // Priority = 3;
	NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}

void configuracao_timer_11(void) {
	// Configura o TIMER 11 para 5ms.
	RCC->APB2ENR|=0x40000;  // inicializa o clock do TIMER11;
	TIM11->CR1|=0x01;  // habilita a contagem do TIMER11;
	TIM11->PSC=799;  // coloca 799 no PSC;
	TIM11->ARR=99;  // coloca 99 no ARR;

	TIM11->DIER|=0x01;  // habilita interrupção do TIMER11;
	// Habilita interrupção no controlador:
	NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, 4);  // Priority = 4;
	NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
}

int main(void)
{
	RCC->AHB1ENR=0x00000087;  // inicializa o clock;
	GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
	GPIOC->MODER=0X00555555;  // configura o pino PC0 ao pino PC11 como saídas;
	configuracao_timer_10();  // configura o TIMER 10;
	configuracao_timer_11();  // configura o TIMER 11;
	while (1)
	{

	}
}
