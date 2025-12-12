#include <stdio.h>

/* Nómina de Profesores
El programa, al recibir como datos los salarios de los profesores de una universidad
, obtiene la nómina y el promedio de los salarios.

I: variables de tipo entero.
SAL, NOM, y PRO: variables de tipo real. */


void main(void)
{
    int I = 0;
    float SAL, PRO, NOM = 0;
    printf("ingrese el salario de profesor:\t");
    /* Observe que al menos se necesita ingresar el salario de un profeso para que no ocurra un error en la ejecución del programa. */
    do
    {
        NOM = NOM + SAL;
        printf("Ingrese el salario del profesor -0 para terminar - :\t");
        scanf("%f", &SAL);
    }
while (SAL);
PRO = NOM / I;
printf("\nNomina: %2f \t Promedio de salarios: %.2f", NOM, PRO);
}
