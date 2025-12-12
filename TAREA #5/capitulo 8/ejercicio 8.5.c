#include <stdio.h>
#include <string.h>

union datos {
char celular[20];
char correo[50];
};

typedef struct {
int matricula;
char nombre[50];
char carrera[50];
float promedio;
union datos personales;
} alumno;

void Lectura(alumno *);

int main(void) {
alumno a1 = {120, "Maria", "Contabilidad", 8.9, {.celular = "5-158-40-50"}};
alumno a2, a3;
printf("Alumno 2\n");
printf("Ingrese la matricula: ");
scanf("%d", &a2.matricula);
fflush(stdin);
printf("Ingrese el nombre: ");
gets(a2.nombre);
printf("Ingrese la carrera: ");
gets(a2.carrera);
printf("Ingrese el promedio: ");
scanf("%f", &a2.promedio);
fflush(stdin);
printf("Ingrese el correo electronico: ");
gets(a2.personales.correo);
printf("Alumno 3\n");
Lectura(&a3);
printf("\nDatos del alumno 1\n");
printf("%d\n", a1.matricula);
puts(a1.nombre);
puts(a1.carrera);
printf("%.2f\n", a1.promedio);
puts(a1.personales.celular);
printf("Ingrese el telefono celular del alumno 2: ");
fflush(stdin);
gets(a2.personales.celular);
puts(a2.personales.celular);
printf("\nDatos del alumno 3\n");
printf("%d\n", a3.matricula);
puts(a3.nombre);
puts(a3.carrera);
printf("%.2f\n", a3.promedio);
puts(a3.personales.celular);
return 0;
}

void Lectura(alumno *a) {
printf("\nIngrese la matricula: ");
scanf("%d", &(*a).matricula);
fflush(stdin);
printf("Ingrese el nombre: ");
gets(a->nombre);
printf("Ingrese la carrera: ");
gets((*a).carrera);
printf("Ingrese el promedio: ");
scanf("%f", &a->promedio);
printf("Ingrese el telefono celular: ");
fflush(stdin);
gets(a->personales.celular);
}
    