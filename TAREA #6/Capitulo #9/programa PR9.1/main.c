#include <stdio.h>

/* Incorpora caracteres.
el pograma agrega acaracteres al libro.txt. */


void main(void)
{
    char p1;
    FILE *ar;
    ar = fopen("libro.txt", "a");
    /* Se abre el archivo con la opinion para incorporar caracteres. */
    if (ar != NULL)
    {
        while ((p1 = getchar()) != "\n")
            fputc(p1, ar);
          fclose(ar);
    }
    else
    printf("No se puede abril el archivo");
    return 0;
}
