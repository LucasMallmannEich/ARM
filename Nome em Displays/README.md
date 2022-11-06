Escrevendo o Nome em Displays de 7 Segmentos Cátodo Comum (MUX)

Considerações:
   - Este código visa fazer um nome ficar rodando num conjunto de 4 displays de 7 segmentos cátodo comum;
   - Os pinos PC0 ao PC7 indicam o controle dos segmentos (que são curto circuitados entre os displays);
   - O pino PC8, PC9, PC10 e PC11 indicam, respectivamente, o segmento comum de cada display cátodo comum;
   - Ou seja, quando o PC8 estiver no GND (0), e o PC9, PC10 e PC11 estiverem no VCC (3.3), apenas o display 1 irá acender.
