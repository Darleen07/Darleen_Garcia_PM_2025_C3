#include <stdio.h>

/* Eñeccion.
El programa almacena los votos emitidos en una eleccion en la que hubo cinco canditades e imprime el total de votos que obtuvo cada uno de ellos. */

void main(void)
{
int ELE[5] = {0};   /* Declaracion del arreglo entero ELE de cinto elementos.  Todos sus elementos se realizan en 0. */
int I, VOT;
printf("Ingrese el primer voto (0 - Para terminar); ");
scanf("%d", &VOT);
while (VOT)
{
    if ((VOT > 0) && (VOT < 6))    /* Verifica que el voto sea correcto. */
        ELE[VOT-1]++;              /* Los vaot se almacenan en el arreglo. Recuerdaque la primera
    posicion del arreglo es 0, por esa razon a la variable VOT se le descuenta 1. Los votos del primer candidato  se almacena en la posicion 0. */
    else
        printf("\nEl voto infresado es incorrecto.\n");
    printf("Ingresa el siguiente voto (0 - para terminar): ");
    scanf("%d", &VOT);
}
printf("\n\nResultado de la Eleccion\n");
for (I = 0; I <= 4; I++)
    printf("\nCandidato %d: %d", I+1, ELE[I]);
}
