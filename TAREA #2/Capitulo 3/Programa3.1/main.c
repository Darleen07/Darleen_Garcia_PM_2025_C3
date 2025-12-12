#include <stdio.h>

/* Nómina
Elprograma, al recibir los salarios de 15 profesores, obtiene el total de la nómina de la universidad.

I: variables de tipo entero
SAL & NOM: variables de tipo real. */


void main(void)
{
int I;
float SAL, NOM;
NOM = 0;

for (I = 1; I <= 15; I++)
{
    printf("\nIngrese el salario del profesor %d:\t", I);
    scanf("%f", &SAL);
    NOM = NOM + SAL;
}
    printf("\nEl total de la nomina es: %.2f", NOM);
}
