#include <stdio.h>
#include <math.h>

/* Expresión.
El programa, al recibir como datos tres valores enteros, establece si los mismos satisfacen una expresión determinada.

R, T y Q; variable de tipo entero.
RES: Variable de tipo real */

void main(void)
{
  float RES;
  int R, T, Q;
  printf(" Ingrese los valores de R, T y Q: ");
  scanf("%d %d %d" , &R, &T, &Q);
  RES = pow (R, 4) - pow(T, 3) + 4 * pow(Q, 2);
  if (RES < 820)

      printf("\nR = %d\tT = %d\t Q = %d" , R, T, Q);

}
