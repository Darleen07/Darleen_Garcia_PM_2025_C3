#include <stdio.h>

 /* Mayor divisor.
 El programa, al recibier ocomo datos un numero entero positivo, calcula su mayor divisor. */

int mad(int);          /* Prototipo de función. */

void main(void)
{
int NUM, RES;
printf("\nIngrese el numero: ");
scanf("%d", &NUM);
RES = mad(NUM);
printf("\nEl mayor divisor de %d es: %d", NUM, RES);
}
int mad(int N1)
/*Esta función calcula el mayor divisor del numero N1. */
{
int I = (N1 / 2);
/* I se iniciliza con el maximo valor posible que puede ser divispor de N1. */
while (N1 % I)
/* El ciclo se mantiene activo mientras (N1 % I) sea distinto a cero.
cuando el resultado sea 0, se detiene, ya que se habra encontrado el mayor divisor de n1. */
I--;
return I;
 }
