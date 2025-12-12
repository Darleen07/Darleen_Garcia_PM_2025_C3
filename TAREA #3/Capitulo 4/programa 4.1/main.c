#include <stdio.h>

/* Cubo-1.
El programa calcula el cubo de los 10 primeros números naturales con la ayuda de una función.
En la solucion del problema se utiliza variables global, aunque esto, como veremos más adelante, no es muy recomendable. */

int cubo(void);          /* Prototipo de función. */
int I;                  /* Variable global. */

void main(void)
{
int CUB;
for (I = 1; I <= 10; I++)
{
    CUB = cubo ();      /* Lamada de la función cubo. */
    printf("\nEl cubo de %d es: %d", I, CUB);
}
}
int cubo(void)          /* Declaracion de la función. */
/* La función calcula el cubo de la variable global I. */
{
return(I*I*I);
}
