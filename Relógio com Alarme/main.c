/*
 * Este código visa simular um relógio digital (horas, minutos e segundos).
 * O programa fica repetindo a palavra "ACORDA" quando o horário chega na hora definida.
 * O horário NÃO fica rodando, a partir do conceito de multiplexação (MUX).
 * A palavra "ACORDA" fica piscando pelos displays durante alguns segundos.
 */

#include "main.h"

// DISPLAY1 - H1, DISPLAY2 - H2, DISPLAY3 - M1, DISPLAY4 - M2, DISPLAY5 - S1, DISPLAY6 - S2
int display1 = 0, display2 = 0, display3 = 0, display4 = 0, display5 = 0, display6 = 0;  // contagem dos 6 displays;
int contador_display = 0;  // indica qual display estamos ligando;
int numeros[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};  // números de 0 à 9;
int estado_atual1=0;
int estado_atual2=0;
int estado_botao = 0;
int h1 = 0, h2 = 1, m1 = 0, m2 = 0;  // horário em que o alarme tocará;
int ajuste = 0;  // 0 para ajustar o relógio e 1 para ajustar o alarme;
int alarme_tocando = 0;  // se tiver 1, o alarme deve tocar;
int alarme[] = {0x77, 0x58, 0x5C, 0x50, 0x5E, 0x77, 0x00};  // letras "A", "C", "O", "R", "D", "A" e " ";
int aux_alarme_display = 0;

void TIM1_UP_TIM10_IRQHandler(){
	if(aux_alarme_display == 0){
		aux_alarme_display = 1;
	}
	else{
		aux_alarme_display = 0;
	}
	// Se algum display passar do número 9 (índice do vetor "numeros[]"), o display volta à zero. Caso contrário, é acrescentado.
	// Os displays também funcionam de acordo com as regras das horas, minutos e segundos.

	// Ajuste do relógio.
	if(ajuste == 0){
		// Ajuste dos minutos.
		if(((GPIOA->IDR)&0x00000003) == 0x0001 && estado_atual1==0){
			estado_atual1 = 1;
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
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && estado_atual1==1){
			estado_atual1 = 0;
		}

		// Ajuste das horas.
		if(((GPIOA->IDR)&0x00000003) == 0x0002 && estado_atual2 == 0){
			estado_atual2 = 1;
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
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && estado_atual2 == 1){
			estado_atual2 = 0;
		}
	}

	// Ajuste do alarme.
	else if(ajuste == 1){
		// Ajuste dos minutos.
		if(((GPIOA->IDR)&0x00000003) == 0x0001 && estado_atual1==0){
			estado_atual1 = 1;
			if(m2 == 9){
				m2 = 0;
				if(m1 == 5){
					m1 = 0;
					if(h2 == 9){
						h2 = 0;
						h1++;
					}
					else if(h2 == 3 && h1 == 2){
						h2 = 0;
						h1 = 0;
					}
					else{
						h2++;
					}
				}
				else{
					m1++;
				}
			}
			else{
				m2++;
			}
		}
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && estado_atual1==1){
			estado_atual1 = 0;
		}

		// Ajuste das horas.
		if(((GPIOA->IDR)&0x00000003) == 0x0002 && estado_atual2 == 0){
			estado_atual2 = 1;
			if(h2 == 9){
				h2 = 0;
				h1++;
			}
			else if(h2 == 3 && h1 == 2){
				h2 = 0;
				h1 = 0;
			}
			else{
				h2++;
			}
		}
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && estado_atual2 == 1){
			estado_atual2 = 0;
		}
	}

	if(display6 == 9){
		display6 = 0;
		if(display5 == 5){
			display5 = 0;
			if(m2 == 9){
				m2 = 0;
				if(m1 == 5){
					m1 = 0;
					if(h2 == 9){
						h2 = 0;
						h1++;
					}
					else if(h2 == 3 && h1 == 2){
						h2 = 0;
						h1 = 0;
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

int i = 801;
int aux_bip = 0;
int bip=0;

void TIM1_TRG_COM_TIM11_IRQHandler(){
	GPIOC->ODR|=0x3F00;  // desligando todos os displays (colocando o segmento comum deles no VCC);
	GPIOC->ODR&=~0xFF;  // limpando os oito bits (colocando zero nos segmentos dos displays);

	// BIP BIP BIP...
	if(alarme_tocando==1 && aux_bip<1000) {
		aux_bip++;
		if(bip == 0){
			bip=1;
			GPIOA->ODR|=0x0020;
		}
		else{
			bip=0;
			GPIOA->ODR&=~(0x0020);
		}
	}
	else{
		aux_bip++;
		if(aux_bip > 2000){
			aux_bip = 0;
		}
	}

	// Ajuste do relógio.
	if(ajuste == 0){
		// Ajuste dos minutos.
		if(((GPIOA->IDR)&0x00000003) == 0x0001 && i>800 && estado_atual1 == 0){
			estado_atual1 = 1;
			i = 0;
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
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && i>800 && estado_atual1 == 1){
			estado_atual1 = 0;
			i++;
		}
		else {
			i++;
		}

		// Ajuste das horas.
		if(((GPIOA->IDR)&0x00000003) == 0x0002 && i>800 && estado_atual2 == 0){
			estado_atual2 = 1;
			i=0;
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
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && i>800 && estado_atual2 == 1){
			estado_atual2 = 0;
			i++;
		}
		else {
			i++;
		}
	}

	// Ajuste do alarme.
	else if(ajuste == 1){
		// Ajuste dos minutos.
		if(((GPIOA->IDR)&0x00000003) == 0x0001 && i>800 && estado_atual1 == 0){
			estado_atual1 = 1;
			i = 0;
			if(m2 == 9){
				m2 = 0;
				if(m1 == 5){
					m1 = 0;
					if(h2 == 9){
						h2 = 0;
						h1++;
					}
					else if(h2 == 3 && h1 == 2){
						h2 = 0;
						h1 = 0;
					}
					else{
						h2++;
					}
				}
				else{
					m1++;
				}
			}
			else{
				m2++;
			}
		}
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && i>800 && estado_atual1 == 1){
			estado_atual1 = 0;
			i++;
		}
		else {
			i++;
		}

		// Ajuste das horas.
		if(((GPIOA->IDR)&0x00000003) == 0x0002 && i>800 && estado_atual2 == 0){
			estado_atual2 = 1;
			i=0;
			if(h2 == 9){
				h2 = 0;
				h1++;
			}
			else if(h2 == 3 && h1 == 2){
				h2 = 0;
				h1 = 0;
			}
			else{
				h2++;
			}
		}
		else if(((GPIOA->IDR)&0x00000003) == 0x0000 && i>800 && estado_atual2 == 1){
			estado_atual2 = 0;
			i++;
		}
		else {
			i++;
		}
	}

	// Verifica qual display "está na sua vez" de ser acionado a partir do zero em seu segmento comum.
	if(ajuste == 0){
		switch(contador_display){
			case 0:
				if(alarme_tocando == 0){
					GPIOC->ODR|=numeros[display1];
				}
				else{
					if(aux_alarme_display == 0){
						GPIOC->ODR|=alarme[0];
					}
					else{
						GPIOC->ODR|=alarme[6];
					}
				}
				GPIOC->ODR&=~0x100;
				break;
			case 1:
				if(alarme_tocando == 0){
					GPIOC->ODR|=numeros[display2];
				}
				else{
					if(aux_alarme_display == 0){
						GPIOC->ODR|=alarme[1];

					}
					else{
						GPIOC->ODR|=alarme[6];
					}
				}
				GPIOC->ODR&=~0x200;
				break;
			case 2:
				if(alarme_tocando == 0){
					GPIOC->ODR|=numeros[display3];
				}
				else{
					if(aux_alarme_display == 0){
						GPIOC->ODR|=alarme[2];
					}
					else{
						GPIOC->ODR|=alarme[6];
					}
				}
				GPIOC->ODR&=~0x400;
				break;
			case 3:
				if(alarme_tocando == 0){
					GPIOC->ODR|=numeros[display4];
				}
				else{
					if(aux_alarme_display == 0){
						GPIOC->ODR|=alarme[3];
					}
					else{
						GPIOC->ODR|=alarme[6];
					}
				}
				GPIOC->ODR&=~0x800;
				break;
			case 4:
				if(alarme_tocando == 0){
					GPIOC->ODR|=numeros[display5];
				}
				else{
					if(aux_alarme_display == 0){
						GPIOC->ODR|=alarme[4];
					}
					else{
						GPIOC->ODR|=alarme[6];
					}
				}
				GPIOC->ODR&=~0x1000;
				break;
			case 5:
				if(alarme_tocando == 0){
					GPIOC->ODR|=numeros[display6];
				}
				else{
					if(aux_alarme_display == 0){
						GPIOC->ODR|=alarme[5];
					}
					else{
						GPIOC->ODR|=alarme[6];
					}
				}
				GPIOC->ODR&=~0x2000;
				break;
		}
	}
	else if(ajuste == 1){
		switch(contador_display){
			case 0:
				GPIOC->ODR|=numeros[h1];
				GPIOC->ODR&=~0x100;
				break;
			case 1:
				GPIOC->ODR|=numeros[h2];
				GPIOC->ODR&=~0x200;
				break;
			case 2:
				GPIOC->ODR|=numeros[m1];
				GPIOC->ODR&=~0x400;
				break;
			case 3:
				GPIOC->ODR|=numeros[m2];
				GPIOC->ODR&=~0x800;
				break;
			case 4:
				GPIOC->ODR|=numeros[0];
				GPIOC->ODR&=~0x1000;
				break;
			case 5:
				GPIOC->ODR|=numeros[0];
				GPIOC->ODR&=~0x2000;
				break;
		}
	}

	// Verifica se o contador do display ultrapassou o número 5 e acresenta-se de acordo com essa informação.
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
	GPIOA->MODER=0x28001400;  // configura a função de Debugger com o ARM e os pinos PA0, PA1 e PA4 (botões) como entradas, com o PA5 e PA6 como saídas (alarme e LED);
	GPIOC->MODER=0X05555555;  // configura o pino PC0 ao pino PC13 como saídas;
	configuracao_timer_10();  // configura o TIMER 10;
	configuracao_timer_11();  // configura o TIMER 11;
	while (1)
	{
		if(((GPIOA->IDR)&0x00000010) == 0x0010 && estado_botao == 0){
			for(int i=0; i<16000; i++){

			}
			if(ajuste == 0){
				ajuste = 1;
				GPIOA->ODR|=0x00000040;  // LED liga indicando que o alarme está sendo configurado;
			}
			else{
				ajuste = 0;
				GPIOA->ODR&=~(0x00000040);  // LED desliga indicando que o relógio está sendo configurado;
			}
			estado_botao = 1;
		}
		else if(((GPIOA->IDR)&0x00000010) == 0x0000 && estado_botao == 1){
			for(int i=0; i<16000; i++){

			}
			estado_botao = 0;
		}
		// Verifica se o alarme deve tocar.
		if(display1 == h1 && display2 == h2 && display3 == m1 && display4 == m2){
			alarme_tocando = 1;
		}
		else{
			alarme_tocando = 0;
		}
	}
}
