#include <stdio.h>

/* Suma pagos
El programa al recibir como datos un conjunto de pagos realizados en el último mes, obtiene la suma de los mismos.

PAG y SPA: variables de tipo real. */

void main(void)
{
 float PAG, SPA;
 SPA = 0;
 printf("Ingrese el primer pago:\t");
 scanf("%f", &PAG);
 while (PAG)
 /* Observe que la condición es verdadero mientras el pago es diferente de cero. */
 {
     SPA = SPA + PAG;
     printf("ingrese el siguinte pago:\t ");
     scanf("%f", &PAG);
     /* Observe que la proposición que modifica la condición es una lectura. */
 }
    printf("\nEl total de los pagos de mes es: %f", SPA);
}
