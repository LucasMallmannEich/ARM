Piscar LEDs em uma Determinada Sequência Repetitiva

Proposta:  
  Criar uma sequência para acender os LEDs.
  
 Sequência de LEDs Alternativa:       
 
 #include "main.h"
                         
void tempo (void) {                     
for (int i=0; i!=1600000; i++);                
}                 
                     
int main(void)              
{             
                                                        
RCC->AHB1ENR=0x00000087;  // inicializa o clock;                                       
GPIOA->MODER=0x28000000;  // inicializa o modo debugger para a interface do ARM;                           
GPIOB->MODER=0x55000454;  // configura os pinos B1, B2, B3, B5, B12, B13, B14, B15 como saídas;                         
                   
while (1)              
{                                             
GPIOB->ODR=0x00000002;  // liga o pino 1;          
tempo();  // espera 1 segundo;   
GPIOB->ODR|=0x00000004;  // liga o pino 2;           
tempo();  // espera 1 segundo;                
GPIOB->ODR|=0x00000008;  // liga o pino 3;          
tempo();  // espera 1 segundo;                   
GPIOB->ODR|=0x00000020;  // liga o pino 5;             
tempo();  // espera 1 segundo;                       
GPIOB->ODR|=0x00001000;  // liga o pino 12;               
tempo();  // espera 1 segundo;                     
GPIOB->ODR|=0x00002000;  // liga o pino 13;           
tempo();  // espera 1 segundo;                     
GPIOB->ODR|=0x00004000;  // liga o pino 14;                
tempo();  // espera 1 segundo;               
GPIOB->ODR|=0x00008000;  // liga o pino 15;               
tempo();  // espera 1 segundo;                
GPIOB->ODR&=0xFFFF7FFF;  // desliga o pino 15;                    
tempo();  // espera 1 segundo;                    
GPIOB->ODR&=0xFFFFBFFF;  // desliga o pino 14;                          
tempo();  // espera 1 segundo;                           
GPIOB->ODR&=0xFFFFDFFF;  // desliga o pino 13;             
tempo();  // espera 1 segundo;                    
GPIOB->ODR&=0xFFFFEFFF;  // desliga o pino 12;              
tempo();  // espera 1 segundo;                     
GPIOB->ODR&=0xFFFFFFDF;  // desliga o pino 5;                 
tempo();  // espera 1 segundo;                             
GPIOB->ODR&=0xFFFFFFF7;  // desliga o pino 3;                
tempo();  // espera 1 segundo;                   
GPIOB->ODR&=0xFFFFFFFB;  // desliga o pino 2;                
tempo();  // espera 1 segundo;                     
GPIOB->ODR&=0xFFFFFFFD;  // desliga o pino 1;               
tempo();  // espera 1 segundo;               
}              
          
