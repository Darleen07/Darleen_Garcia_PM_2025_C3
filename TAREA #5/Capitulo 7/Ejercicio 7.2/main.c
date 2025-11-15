#include <stdio.h>
#include <stdlib.h>
/* Suma y promedio.
El programa, al recibir como datos varias cadenas de caracteres que
contienen reales, los suma y obtiene el promedio de los mismos. */
void main(void)
{
char c, cad[10];
int i = 0;
float sum = 0.0;
printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
c = getchar();
while (c == 'S' || c == 's') // Se corrige la comilla simple
{
    printf("\nIngrese la cadena de caracteres: ");
    fflush(stdin);
    gets(cad);
    i++; // Se corrige la coma al final de la línea.
    sum += atof(cad);
    printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
    fflush(stdin); // Se añade fflush para limpiar el buffer antes de leer el caracter 'S/N'
    c = getchar();
}
printf("\nSuma: %.2f", sum);
printf("\nPromedio: %.2f", sum / i);
}
