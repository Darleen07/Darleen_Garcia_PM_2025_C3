#include <stdio.h>
#include <stdlib.h>

/* Mezcla.
El programa mezcla, respetando el orden, dos archivos que se encuentran
ordenados en forma ascendente considerando la matrícula de los alumnos. */

void mezcla(FILE *, FILE *, FILE *); /* Prototipo de función. */

int main(void)
{
    FILE *ar, *ar1, *ar2;

ar = fopen("C:/Users/sv988/Desktop/programacion 2/Tarea #6/Capitulo #9/programa RP9.5/bin/Debug/arc9.dat", "r");
ar1 = fopen("C:/Users/sv988/Desktop/programacion 2/Tarea #6/Capitulo #9/programa RP9.5/bin/Debug/arc10.dat", "r");
ar2 = fopen("C:/Users/sv988/Desktop/programacion 2/Tarea #6/Capitulo #9/programa RP9.5/bin/Debug/arc11.dat", "w");

    if (((ar != NULL) && (ar1 != NULL)) && (ar2 != NULL))
    {
        printf("Archivos abiertos con exito. Ejecutando mezcla...\n");

        mezcla(ar, ar1, ar2);

        fclose(ar);
        fclose(ar1);
        fclose(ar2);

        printf("Mezcla finalizada. Revisa arc11.dat\n");
    }
    else
    {
        // Mensaje de error detallado para el diagnóstico
        printf("ERROR: No se pudieron abrir los archivos.\n");
        if (ar == NULL) printf("  - Fallo al abrir arc9.dat\n");
        if (ar1 == NULL) printf("  - Fallo al abrir arc10.dat\n");
        if (ar2 == NULL) printf("  - Fallo al abrir arc11.dat (Verifica permisos de escritura)\n");
    }

    return 0;
}

void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
/* Esta función mezcla, respetando el orden, dos archivos que se encuentran
ordenados en función de la matrícula. */
{
    int i, mat, mat1, b = 1, b1 = 1;
    float ca[3], ca1[3], cal;

    // Bucle principal: mezcla mientras haya datos que comparar en ambos archivos
    while (((!feof(ar)) || !b) && ((!feof(ar1)) || !b1))
    {
        if (b) /* Si la bandera b está encendida, se lee del archivo ar. */
        {
            if (fscanf(ar, "%d", &mat) != 1) break; // Si no lee la matrícula, sale
            for (i = 0; i < 3; i++)
                fscanf(ar, "%f", &ca[i]);
            b = 0;
        }

        if (b1) /* Si la bandera b1 está encendida, se lee del archivo ar1. */
        {
            if (fscanf(ar1, "%d", &mat1) != 1) break; // Si no lee la matrícula, sale
            for (i = 0; i < 3; i++)
                fscanf(ar1, "%f", &ca1[i]);
            b1 = 0;
        }

        if (mat < mat1)
        {
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca[i]);
            fputs("\n", ar2);
            b = 1; // Necesitamos leer el siguiente dato de ar
        }
        else
        {
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca1[i]);
            fputs("\n", ar2);
            b1 = 1; // Necesitamos leer el siguiente dato de ar1
        }
    }

    // Bloque IF: Terminar de copiar lo que queda del primer archivo (ar)
    if (!b)
    {
        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca[i]);
        fputs("\n", ar2);

        while (!feof(ar))
        {
            if (fscanf(ar, "%d", &mat) != 1) break;
            fprintf(ar2, "%d\t", mat);

            for (i = 0; i < 3; i++)
            {
                if (fscanf(ar, "%f", &cal) != 1) break;
                fprintf(ar2, "%f\t", cal);
            }
            fputs("\n", ar2);
        }
    }

    // Bloque IF: Terminar de copiar lo que queda del segundo archivo (ar1)
    if (!b1)
    {
        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca1[i]);
        fputs("\n", ar2);

        while (!feof(ar1))
        {
            if (fscanf(ar1, "%d", &mat1) != 1) break;
            fprintf(ar2, "%d\t", mat1);

            for (i = 0; i < 3; i++)
            {
                if (fscanf(ar1, "%f", &cal) != 1) break;
                fprintf(ar2, "%f\t", cal);
            }
            fputs("\n", ar2);
        }
    }
}
