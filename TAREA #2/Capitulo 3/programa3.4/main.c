#include <stdio.h>
#include <math.h>

/* suma cuadrados.
El programa al recibir como datos un grupo de positicos, obtiene el cuadrado de los mismos y la suma
correspondinete a dicho cuadrados. */

void main(void)
{
 int NUM;
 long CUA, SUC = 0;
 printf("\nIngresa un numero entero -0 para terminar-:\t");
 scanf("%d", &NUM);
 while (NUM)
    /*Observe que la condición es verdadera mientras el entero es diferente de cero. */
 {
     CUA = pow (NUM, 2);
     printf("%d al cubo es %1d", NUM, CUA);
     SUC = SUC + CUA;
     printf("\nIngrese un número entre -0 para terminar-:\t");
     scanf("%d", &NUM);
 }
   printf("\nLa suma de los cuadrados es %1d", SUC);
}
