#include <stdio.h>

/* Cubo-3.
El programa calcula el cubo de los 10 primeros números naturales
con la ayuda de una función y utiliza parametros por el valor. */

int cubo(int);         /* Prototipo de función. el parámetro es
                        de tipo entero. */

void main(void)
{
int I;
for (I = 1; I <= 10; I++)
    printf("\nEl cubo de I es:%d", cubo(I));
/* Llamda de la función cubo. El paso del parametro es por valor. */
}
int cubo(int K)        /* K es un parámetro por valpor de tipo entero. */
/* La función calcula el cubo del parametro K. */
{
    return (K*K*K);
}
