#include <stdio.h>

/* Archivos con varaibles y entradas reales.
El programa lee informacion de los alumnos de una escuela, almacenada en un
archivo. Utiliza una funcion para realizar la lectura, pero el archivo abre
y cierra desde el programa principal. */

void promedio(FILE*);
/* Prototipo de funcion. Se pasa un archivo como parametro. */


void main(void)
{
FILE *ar;
if ((ar= fopen("arc9.txt", "r")) != NULL)
{
    promedio(ar);       /* Se llama a la funcion promedio. Observe que la forma
                            como se pasa el archivo como parametro. */

    fclose(ar);
}
else
    printf("No se puede abrir el archivo");
    return 0;
}

void promedio(FILE *ar1)      /* Observe la forma como se recive el archivo. */
/* Esta funcion lee los datos de los alumnos desde un archivo, e imprime tanto
la matricula como el promedio de cada alumno. */

{
int i, j, n, mat;
float pro, cal;
fscanf(ar1, "%d", &n);
for (i=0; i<n; i++)
{
    fscanf(ar1, "%d", &mat);
    printf("%d\t" , mat);
     pro = 0;
     for (j =0; j <5; j++)
     {
         fscanf(ar1, "%f", &cal);
         pro += cal;
     }
     printf("\t %.2f ", pro/5 );
     printf("\n");
}

}
