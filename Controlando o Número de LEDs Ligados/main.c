/*
  Este código visa controlar LEDs por meio de três chaves.
*/

#include "main.h"

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
  GPIOB->MODER=0x55000054;  // configura os pinos B1, B2, B3, B12, B13, B14 e B15 com a função de saída;
  // Os pinos B6, B8 e B9 serão usados como as chaves do circuito, sendo utilizada a sua função de leitura de valores.
  // O pino B6 é a chave 0, o pino B8 é a chave 1 e o pino B9 é a chave 2.
  // ((GPIOB->IDR)&0x00000040) ---> testa o pino B6
  // ((GPIOB->IDR)&0x00000100) ---> testa o pino B8
  // ((GPIOB->IDR)&0x00000200) ---> testa o pino B9
  
  while (1)
  {
	  if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
		  GPIOB->ODR=0x00000000;  // desliga todos os pinos;
	  }
	  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
		  GPIOB->ODR=0x00000002;  // liga o pino 1;
	  }
	  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
		  GPIOB->ODR=0x00000006;  // liga o pino 1 e 2;
	  }
	  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
		  GPIOB->ODR=0x0000000E;  // liga o pino 1, 2 e 3;
	  }
	  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x0000100E;  // liga o pino 1, 2, 3 e 12;
	  }
	  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x0000300E;  // liga o pino 1, 2, 3, 12 e 13;
	  }
	  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x0000700E;  // liga o pino 1, 2, 3, 12, 13 e 14;
	  }
	  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x0000F00E;  // liga o pino 1, 2, 3, 12, 13, 14 e 15;
	  }
  }
}
