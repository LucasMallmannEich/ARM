/*
  Este c�digo visa controlar LEDs por meio de tr�s chaves.
*/

#include "main.h"

void tempo(void) {
	for(int i=0; i<800000; i++);
}

void liga_1(void) {
	GPIOB->ODR=0x00000002;
	tempo();
}

void liga_2(void) {
	GPIOB->ODR=0x00000002;
	tempo();
	GPIOB->ODR|=0x00000004;
	tempo();
}

void liga_3(void) {
	GPIOB->ODR=0x00000002;
	tempo();
	GPIOB->ODR|=0x00000004;
	tempo();
	GPIOB->ODR|=0x00000008;
	tempo();
}

void liga_4(void) {
	GPIOB->ODR=0x00000002;
	tempo();
	GPIOB->ODR|=0x00000004;
	tempo();
	GPIOB->ODR|=0x00000008;
	tempo();
	GPIOB->ODR|=0x00001000;
	tempo();
}

void liga_5(void) {
	GPIOB->ODR=0x00000002;
	tempo();
	GPIOB->ODR|=0x00000004;
	tempo();
	GPIOB->ODR|=0x00000008;
	tempo();
	GPIOB->ODR|=0x00001000;
	tempo();
	GPIOB->ODR|=0x00002000;
	tempo();
}

void liga_6(void) {
	GPIOB->ODR=0x00000002;
	tempo();
	GPIOB->ODR|=0x00000004;
	tempo();
	GPIOB->ODR|=0x00000008;
	tempo();
	GPIOB->ODR|=0x00001000;
	tempo();
	GPIOB->ODR|=0x00002000;
	tempo();
	GPIOB->ODR|=0x00004000;
	tempo();
}

void liga_7(void) {
	GPIOB->ODR=0x00000002;
	tempo();
	GPIOB->ODR|=0x00000004;
	tempo();
	GPIOB->ODR|=0x00000008;
	tempo();
	GPIOB->ODR|=0x00001000;
	tempo();
	GPIOB->ODR|=0x00002000;
	tempo();
	GPIOB->ODR|=0x00004000;
	tempo();
	GPIOB->ODR|=0x00008000;
	tempo();
}

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
  // O pino B10 vai ser usado como um bot�o que ir� fazer os LEDs ligarem em sequ�ncia.
  
  while(((GPIOB->IDR)&0x00000400) == 0x00000000) {
  }
  
  if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
	  GPIOB->ODR=0x00000000;  // desliga todos os pinos;
  }
  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
	  liga_1();  // liga o pino 1;
  }
  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
  	  liga_2();  // liga o pino 1 e 2;
  }
  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) == 0x0) {
  	  liga_3();  // liga o pino 1, 2 e 3;
  }
  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
  	  liga_4();  // liga o pino 1, 2, 3 e 12;
  }
  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) == 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
  	  liga_5();  // liga o pino 1, 2, 3, 12 e 13;
  }
  else if (((GPIOB->IDR)&0x00000040) == 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
  	  liga_6();  // liga o pino 1, 2, 3, 12, 13 e 14;
  }
  else if (((GPIOB->IDR)&0x00000040) != 0x0 && ((GPIOB->IDR)&0x00000100) != 0x0 && ((GPIOB->IDR)&0x00000200) != 0x0) {
	  liga_7();  // liga o pino 1, 2, 3, 12, 13, 14 e 15;
  }

  while (1)
  {
	  GPIOB->ODR=0x00000000;  // desliga todos os pinos;
	  tempo();
	  GPIOB->ODR=0x0000F00E;  // liga o pino 1, 2, 3, 12, 13, 14 e 15;
	  tempo();
  }
}
