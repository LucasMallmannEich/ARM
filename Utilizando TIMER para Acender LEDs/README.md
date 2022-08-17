Utilização de TIMER para LEDs

Proposta:
  - Ligar LEDs em uma determinada sequência;
  - O tempo de acionamento entre cada LED deve ser bem definido (100 ms);
  - Utilize um TIMER para realizar o código;
  - T = (1 / f) . ARR . PSC
  - Onde: 
  - T ---> tempo que ele vai contar;
  - f ---> frequência do ARM (16 MHz);
  - ARR e PSC devem ser um valor entre 0 e 65535.
