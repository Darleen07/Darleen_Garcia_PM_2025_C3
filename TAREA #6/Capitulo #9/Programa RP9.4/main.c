#include <stdio.h>
#include <ctype.h>

/* Letras minúsculas y mayúsculas.
El programa, al recibir como dato un archivo formado por cadenas de
caracteres, determina el número de letras minúsculas y mayúsculas que hay
en el archivo. */

void minymay(FILE *);             /* Prototipo de función. */

void main(void)
{
    FILE *ap;
    if ((ap = fopen ("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");
}

void minymay(FILE *ap1)
/* Esta función se utiliza para leer cadenas de caracteres de un archivo
y contar el número de letras minúsculas y mayúsculas que existen en el
archivo. */
{
    char cad[30];
    int i, mi = 0, ma = 0;
    while (fgets(cad, 30, ap1) != NULL)
    {
        fgets(cad,30,ap1);
        /* Se utiliza la función fgets() para leer cadenas de caracteres del
        archivo. */
        i = 0;
        while (cad[i] != '\0')
        {
            if (islower(cad[i]))
                mi++;
            else
                if (isupper(cad[i]))
                    ma++;
            i++;
        }
    }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
}
