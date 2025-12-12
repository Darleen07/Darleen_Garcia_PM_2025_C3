#include <stdio.h>

/* Paso de una función como parámetro por referencia. */

int Suma(int X, int Y)
/* La funcion suma regresa la suma a los parámetros de tipo entero X y Y. */

{
return (X+Y);
}

int Resta(int X, int Y)
/* Esta funcion regresa la recta de los parámetros de tipo entero X y Y. */
{
return (X-Y);
}
int Control(int(*apf) (int, int), int X, int Y)
/* *Esta función recibe como parámetro otra funcion -la dirección- y dependiendo de cuál sea ésta, llama a la función suna o resta. */
{
int RES;
RES = (*apf) (X, Y);          /* Se llama a la fución suma o resta. */
return (RES);
}

void main(void)
{
int R1, R2;
R1 = Control(Suma, 15, 5);  /* Se pasa como parámetro de la función suma. */
R2 = Control(Resta, 10, 4); /* Se pasa como parámetro de la función resta. */
printf("\nResultado 1: %d", R1);
printf("\nResultado 2: %d", R2);

return 0;
}
