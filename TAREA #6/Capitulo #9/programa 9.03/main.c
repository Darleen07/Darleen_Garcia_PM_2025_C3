#include <stdio.h>

/* Archivo y cadenas de caracteres.
El programa escribe cadenas de caracteres en un archivo. */


void main(void)
{
char cad[50];
int res;
FILE *ar;
if ((ar = fopen("arc.txt", "w")) != NULL)
/* Se abre el archivo para escritura. En la misma intrucciones se verifica si se pudo abril. */
{
printf("\n¿Desea ingresar una cadena de caracteres? si-1 no-0:");
scanf("%d", &res);
while (res)
{
    fflush(stdin);
    printf("Ingrese la cadena: ");
    gets(cad);
    fputs(cad, ar);   /* Observa la forma como se escribe la cadena en el archivo. */

    printf("\n¿Desea ingresar otra cadena de caracteres? si-1 no-0:");
    scanf("%d", &res);
    if (res)
        fputs("\n", ar);
    /* Se indica un salto de linea, excepto en la ultima cadena. si no se heciera esta
    indicacion, la funcion fputs pegaria la cadenas y luego tendriammos dificultades en el momento de leerlas.
    Por otra parte, si realizamos este salto de linea al final de la ultima caddena,
    en la escritura se repetira la ultima cadena. */
}
fclose(ar);

}
else
    printf("no se puede abril el atrchivo");

}
