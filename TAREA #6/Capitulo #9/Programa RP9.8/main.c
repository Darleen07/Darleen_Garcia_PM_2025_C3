#include <stdio.h>

/* Ordenar de menor a mayor.
El programa ordena de menor a mayor en funcion de la matricula, creando un nuevo archivo.
un archivo de acceso directo compuesto por estructuras y ordenado de mayor a manor. */

typedef struct    /* Declaracion de la estructura alumno. */

{
  int matricula;
  char nombre[20];
  int carrera;
  float promedio;
} alumno;

void ordena(FILE *, FILE *);     /* Prototipo de funcion. */

void main(void)
{
    FILE *ar1, *ar2;
    ar1 = fopen("ad5.dat", "r");
    ar2 = fopen("ad6.dat", "w");
    if ((ar1 != NULL) && (ar2 != NULL))
        ordena(ar1, ar2);
    else
        printf("\nEl o los archivos no se pudieron abrir");
    fclose(ar1);
    fclose(ar2);
}
void ordena(FILE *ap1, FILE *ap2)
/* Esta funcion ordena de menor a mayor un archivo compuesto por estructuras,
en funcion de su matricula, y genera un nuevo archivo. */
{
    alumno alu;
    int t, n, i;
    t = sizeof(alumno);
    fseek (ap1, sizeof(alumno), 2);
    n = (ftell(ap1)/ t)-1;
    /* Se obtiene el numero de registro que componen el archivo. el valor de n,
    a su vez, se utilizara para posicionarnos en el archivo. */
    rewind(ap1);
    for (i = (n-1); i>= 0; i--)   /* Se utiliza un ciclo desendente. */
    {
        fseek(ap1, i * sizeof(alumno), 0);
        fread(&alu, sizeof(alumno), 1, ap1);
        fwrite(&alu,sizeof(alumno), 1, ap2);
    }
}
