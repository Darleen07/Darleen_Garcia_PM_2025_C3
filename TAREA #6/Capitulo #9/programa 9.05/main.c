#include <stdio.h>

/* Archivo con variables enteras y reales
El rpgrama almacena datos de un grupo de alumnos en un archivo */

void main(void)
{
int i, j, n, mat;
float cal;
FILE *ar;
printf("\nIngrese el numero de alumnos: ");
scanf("%d" , &n);
/* se asume que el valor que ingresa el usuario esta comprimido entre 1 y 35. */
if ((ar = fopen("arc8.txt" , "w")) != NULL)
{
    fprintf(ar,"%d" , n);   /* SDe escribe el numero de alumnos en el archivo. */

    for (i=0; 1<n; i++)

    {
        printf("\nIngrese la matricula del alumno %d: i+1");
        scanf("%d", &mat);
        fprintf(ar, "\n%d", mat);   /* Se escribe la matricula en el archivo. */
        for (j=0; j<5; j++)
        {
            printf("\nCalificacion %d: ", j+1);
            scanf("%f", &cal);
            fprintf(ar, "%2f", cal);   /* Se escribe las calificaciones en el archivo. */
        }
    }
    fclose(ar);
}
else
    printf("No se puede abril el archivo");

}
