/*
	Este código visa juntar, por meio do uso de duas chaves, 3 sequências de acionamentos de LEDs diferentes.
*/

#include "main.h"

// Declaração da variável "seq", que irá dizer qual será a sequência.
int seq;

// Função que contabiliza 200 ms.
void tempo (void) {
	while((TIM10->SR & 0x0001) == 0x0000) {  // verifica se o cronômetro foi "setado" (acabou a contagem);
		// enquanto o cronômetro não for "setado para 1", a contagem irá continuar dentro desse while;
		if ((GPIOC->IDR & 0x00000300) == 0x00000000) {
		    seq = 1;
		}
	    else if ((GPIOC->IDR & 0x00000300) == 0x00000300) {
	    	seq = 2;
	    }
	    else {
	    	seq = 3;
	    }
	}
	TIM10->SR&=~(0x0001);  // "resetar" o cronômetro, botando zero no bit em questão;
}

void sequencia_1 (void) {
	 GPIOC->ODR=(0x00000000);  // apaga todos os 8 LEDs;
	 GPIOC->ODR|=0x00000001;  // acende o LED1;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000001);  // apaga o LED1;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
	 	sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000002;  // acende o LED2;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000002);  // apaga o LED2;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000004;  // acende o LED3;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000004);  // apaga o LED3;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000008;  // acende o LED4;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000008);  // apaga o LED4;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000010;  // acende o LED5;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000010);  // apaga o LED5;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000020;  // acende o LED6;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000020);  // apaga o LED6;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000040;  // acende o LED7;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000040);  // apaga o LED7;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000080;  // acende o LED8;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000080);  // apaga o LED8;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000040;  // acende o LED7;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000040);  // apaga o LED7;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000020;  // acende o LED6;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000020);  // apaga o LED6;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000010;  // acende o LED5;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000010);  // apaga o LED5;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000008;  // acende o LED4;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000008);  // apaga o LED4;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000004;  // acende o LED3;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000004);  // apaga o LED3;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000002;  // acende o LED2;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000002);  // apaga o LED2;
	 tempo();  // contabiliza 200 ms;
	 if (seq == 2) {
		 sequencia_2();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
}

void sequencia_2(void) {
	GPIOC->ODR=(0x00000000);  // apaga todos os 8 LEDs;
	GPIOC->ODR|=0x00000001;  // acende o LED1;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000002;  // acende o LED2;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000004;  // acende o LED3;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000008;  // acende o LED4;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000010;  // acende o LED5;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000020;  // acende o LED6;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000040;  // acende o LED7;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR|=0x00000080;  // acende o LED8;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000080);  // apaga o LED8;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000040);  // apaga o LED7;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000020);  // apaga o LED6;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000010);  // apaga o LED5;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000008);  // apaga o LED4;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000004);  // apaga o LED3;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000002);  // apaga o LED2;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
	 GPIOC->ODR&=~(0x00000001);  // apaga o LED1;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 3) {
		 sequencia_3();
	 }
}

void sequencia_3(void) {
	 GPIOC->ODR=(0x00000000);  // apaga todos os 8 LEDs;
	 GPIOC->ODR|=0x00000001;  // acende o LED1;
	 GPIOC->ODR|=0x00000080;  // acende o LED8;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
	 GPIOC->ODR|=0x00000002;  // acende o LED2;
	 GPIOC->ODR|=0x00000040;  // acende o LED7;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
	 GPIOC->ODR|=0x00000004;  // acende o LED3;
	 GPIOC->ODR|=0x00000020;  // acende o LED6;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
	 GPIOC->ODR|=0x00000008;  // acende o LED4;
	 GPIOC->ODR|=0x00000010;  // acende o LED5;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
	 GPIOC->ODR&=~(0x00000010);  // apaga o LED5;
	 GPIOC->ODR&=~(0x00000008);  // apaga o LED4;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
	 GPIOC->ODR&=~(0x00000020);  // apaga o LED6;
	 GPIOC->ODR&=~(0x00000004);  // apaga o LED3;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
	 GPIOC->ODR&=~(0x00000040);  // apaga o LED7;
	 GPIOC->ODR&=~(0x00000002);  // apaga o LED2;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
	 GPIOC->ODR&=~(0x00000080);  // apaga o LED8;
	 GPIOC->ODR&=~(0x00000001);  // apaga o LED1;
	 tempo();  // espera 200 ms;
	 if (seq == 1) {
		 sequencia_1();
	 }
	 else if (seq == 2) {
		 sequencia_2();
	 }
}

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  RCC->APB2ENR|=0x20000;  // inicializa o clock do TIMER10;
  TIM10->CR1|=0x0005;  // habilita a contagem do TIMER10;
  TIM10->PSC=99;  // coloca o PSC para 99;
  TIM10->ARR=31999;  // coloca o ARR para 31999;
  GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
  GPIOC->MODER=0x00005555;  // pinos PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7 - saídas e pinos PC8 e PC9 - entradas;

  while (1)
  {
    if ((GPIOC->IDR & 0x00000300) == 0x00000000) {
    	sequencia_1();
    }
    else if ((GPIOC->IDR & 0x00000300) == 0x00000300) {
    	sequencia_2();
    }
    else {
    	sequencia_3();
    }
  }
}
