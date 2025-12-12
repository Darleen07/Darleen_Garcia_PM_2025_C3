#include <stdio.h>

/* Archivo y caracteres.
El programa escribe caracteres en un archivo. */

void main(void)
{
char p1;
FILE *ar;
ar = fopen("arc.txt", "w");    /* se abre el archivo arc.txt para escritura. */
if (ar != NULL)
{
    while ((p1=getchar())!= "\n")
        /* se escribe caracteres en el archivo mientras se detecta el caracter
        queb indica el final de la linea. */
           fputc(p1, ar);
    fclose(ar);        /* se cierra el archivo. */
}
else
    printf("No se puede abrir el archivo");
    return 0;
}
