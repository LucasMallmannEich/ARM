/*
  Este código visa controlar LEDs por meio de uma chave.
*/

#include "main.h"

int num = 0;
int estado_atual = 0;

void teste(void) {
	for(int i=0; i!=16000; i++);
	if ((estado_atual == 0) && ((GPIOB->IDR & 0x00000100) != 0x0)) {
		estado_atual = 1;
		if (num == 8) {
			num = 0;
		}
		else {
			num = num + 1;
		}
	}
	if ((estado_atual == 1) && ((GPIOB->IDR&0x00000100) == 0x0)){
		estado_atual = 0;
	}
}

int main(void)
{
  RCC->AHB1ENR=0x00000087;  // inicializa o clock;
  GPIOA->MODER=0x28000000;  // configura a função de Debugger com o ARM;
  GPIOB->MODER=0x55000454;  // configura os pinos B1, B2, B3, B5, B12, B13, B14 e B15 com a função de saída;
  // O pino B8 será usado como a chave do circuito, sendo utilizada a sua função de leitura de valores.
  // ((GPIOB->IDR)&0x00000100) ---> testa o pino B8

  while (1)
  {
	 teste();
	 if (num == 0) {
	 GPIOB->ODR=0x00000000;  // desliga todos os pinos;
	 }
	 else if (num == 1) {
	 GPIOB->ODR=0x00000002;  // liga o pino 1;
	 }
	 else if (num == 2) {
	 GPIOB->ODR=0x00000006;  // liga o pino 1 e 2;
	 }
	 else if (num == 3) {
	 GPIOB->ODR=0x0000000E; // liga o pino 1, 2 e 3;
	 }
	 else if (num == 4) {
	 GPIOB->ODR=0x0000002E;  // liga o pino 1, 2, 3 e 5;
	 }
	 else if (num == 5) {
	 GPIOB->ODR=0x0000102E;  // liga o pino 1, 2, 3, 5 e 12;
	 }
	 else if (num == 6) {
	 GPIOB->ODR=0x0000302E;  // liga o pino 1, 2, 3, 5, 12 e 13;
	 }
	 else if (num == 7) {
	 GPIOB->ODR=0x0000702E;  // liga o pino 1, 2, 3, 5, 12, 13 e 14;
	 }
	 else if (num == 8) {
	 GPIOB->ODR=0x0000F02E;  // liga o pino 1, 2, 3, 5, 12, 13, 14 e 15;
	 }
  }
}
