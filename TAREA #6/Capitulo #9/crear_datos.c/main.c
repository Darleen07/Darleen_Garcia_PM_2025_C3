#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// La misma estructura de tu programa principal
typedef struct
{
 int clave;
 char nombre[20];
 int carrera;
 float promedio;
 float examen;
 char telefono[12];
} alumno;

int main()
{
    FILE *ap;
    // Abrir el archivo en modo escritura binaria ("wb")
    ap = fopen("alu1.dat", "wb");

    if (ap == NULL) {
        printf("Error al crear alu1.dat. Revise permisos de carpeta.\n");
        return 1;
    }

    // --- Registros de Ejemplo ---
    // (Carrera 1, Admitido: examen >= 1300 y promedio >= 8)
    alumno a1 = {101, "Juan Perez", 1, 9.5, 1350.0, "5551111111"};

    // (Carrera 2, Admitido: examen >= 1400 y promedio >= 7)
    alumno a2 = {102, "Ana Lopez", 2, 7.8, 1450.0, "5552222222"};

    // (Carrera 3, No Admitido)
    alumno a3 = {103, "Luis Gomez", 3, 6.5, 1200.0, "5553333333"};

    // (Carrera 1, Admitido)
    alumno a4 = {104, "Maria Diaz", 1, 8.2, 1310.0, "5554444444"};

    // Escribir los registros en el archivo
    fwrite(&a1, sizeof(alumno), 1, ap);
    fwrite(&a2, sizeof(alumno), 1, ap);
    fwrite(&a3, sizeof(alumno), 1, ap);
    fwrite(&a4, sizeof(alumno), 1, ap);

    printf("Archivo alu1.dat creado con 4 registros de ejemplo en la carpeta de ejecucion.\n");

    fclose(ap);
    return 0;
}
