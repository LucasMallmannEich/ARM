/*
  Este c�digo visa controlar LEDs por meio de tr�s chaves.
*/

#include "main.h"

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  GPIOA->MODER=0x28000000;  // configura a fun��o de Debugger com o ARM;
  GPIOB->MODER=0x55000054;  // configura os pinos B1, B2, B3, B12, B13, B14 e B15 com a fun��o de sa�da;
  // Os pinos B6, B8 e B9 ser�o usados como as chaves do circuito, sendo utilizada a sua fun��o de leitura de valores.
  // O pino B6 � a chave 0, o pino B8 � a chave 1 e o pino B9 � a chave 2.
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
		  GPIOB->ODR=0x00000004;  // liga o pino 2;
	  }
	  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
		  GPIOB->ODR=0x00000008;  // liga o pino 3;
	  }
	  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x00001000;  // liga o pino 12;
	  }
	  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x00002000;  // liga o pino 13;
	  }
	  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x00004000;  // liga o pino 14;
	  }
	  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
		  GPIOB->ODR=0x00008000;  // liga o pino 15;
	  }
  }
}
