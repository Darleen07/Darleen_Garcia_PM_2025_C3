#include <stdio.h>
#include <math.h>

/* Pres e impares.
El programa,al recibir como datos N numericos enteros, culcula cuantos
de ellos son pares y cuantos impares, con la ayuda de una funcion. */

void parimp (int, int *, int*);

void main(void)
{
int I, N, NUM, PAR = 0, IMP = 0;
printf("%d", &N);
scanf("%d", &N);
for (I =1; I <= N; I++)
}
   printf("nIngresa el numero %d:", I);
   scanf("%d", & NUM);
   parimp(NUM,&PAR, &IMP);
   /* Llamada a la funcion. Paso de parámetros por valor y por referencia. */
{
printf("\nNumero de pares: %d", PAR);
printf("\nNumero de impares: %d", IMP);
}
void parimp(int NUM, int *P, int *I)
/* La funcion incrementa el parametro *P o *I, segun se ek numero par o impar. */
{
int RES;
RES = pow(-1, NUM);
if (RES > 0)
    *P += 1;
else
    if (RES < 0)
       *I += 1;
}
