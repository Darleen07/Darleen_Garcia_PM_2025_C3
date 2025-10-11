#include <stdio.h>

/* Productoria.
El programa calcula la productividad de los N primeros números naturales. */

int productoria(int);                 /* Prototipo de funcón. */

void main(void)
{
int NUM;
/* Se escribe un do-while para verificar que el numero del cual se quiere calcular la productoria sea correcto. */
do
 {
     printf("Ingrese el numero del cual quiere la productoria: ");
     scanf("%d", &NUM);
 }
while (NUM >100 || NUM < 1);
printf("\nLa productoria de %d es: %d", NUM, productoria(NUM));
}
int productoria (int N)
/* La funcion calcular la productoria de N. */
{
int I, PRO = 1;
for (I = 1; I <= N; I++)
    PRO *= I;
return(PRO);
}
