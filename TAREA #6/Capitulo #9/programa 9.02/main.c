#include <stdio.h>

/*Archivos y caracteres.
El programa lee caracteres de un archivo. */

void main(void)
{
char p1;
FILE *ar;
if ((ar = fopen("arc.txt", "r"))!= NULL)  /* Se abre el aechivo para lectura. */
    /* Observe que las dos intucciones del programa 9.1 necesarias parea abril un archivo
    y verificar que este en realidad se haya abierto, se pueden agrupar en una sola intruccion. */
{
    while (!feof(ar))
        /* Se leen caracteres del archivo mientras no se detecte el final del archivo. */
    {
      p1 = fgetc(ar);    /* lee el caracter del archivo. */
      putchar(p1);       /* Despliega el caracter en la pantalla. */
    }
    fclose(ar);
}
else
    printf("No se puede abril el archivo");
}
