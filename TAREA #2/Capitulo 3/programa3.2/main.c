#include <stdio.h>

/* Suma positivos
El programa, al recibir como datos N números enteros, Obtiene la suma de los enteros positivos.

I, N, NUM, SUM: variables de tipo entero. */

void main(void)
{
 int I, N, NUM, SUM;
 SUM = 0;
 printf("\nIngrese el número de datos:\t", I);
 scanf("%d", &N);
 for (I=1; I<=N; I++)
 {
  printf("Ingrese el dato de número %d:\t", I);
  scanf("%d", &N);
  if (NUM > 0)
      SUM = SUM + NUM;
 }
printf("\nLa suma de los positivos es: %d", SUM);

}
