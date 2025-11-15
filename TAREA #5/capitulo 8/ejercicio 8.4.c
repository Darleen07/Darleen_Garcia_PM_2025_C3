#include <stdio.h>
#include <string.h>

typedef struct {
int matricula;
char nombre[50];
float cal[5];
} alumno;

void Lectura(alumno[], int);
void F1(alumno[], int);
void F2(alumno[], int);
void F3(alumno[], int);

int main(void) {
alumno ARRE[50];
int TAM;
do {
printf("Ingrese el tamano del arreglo: ");
scanf("%d", &TAM);
} while (TAM > 50 || TAM < 1);
Lectura(ARRE, TAM);
F1(ARRE, TAM);
F2(ARRE, TAM);
F3(ARRE, TAM);
return 0;
}

void Lectura(alumno A[], int T) {
int I, J;
for (I = 0; I < T; I++) {
printf("\nIngrese los datos del alumno %d\n", I + 1);
printf("Ingrese la matricula del alumno: ");
scanf("%d", &A[I].matricula);
fflush(stdin);
printf("Ingrese el nombre del alumno: ");
gets(A[I].nombre);
for (J = 0; J < 5; J++) {
printf("\tIngrese la calificacion %d del alumno %d: ", J + 1, I + 1);
scanf("%f", &A[I].cal[J]);
}
}
}

void F1(alumno A[], int T) {
int I, J;
float SUM, PRO;
for (I = 0; I < T; I++) {
printf("\nMatricula del alumno: %d", A[I].matricula);
SUM = 0.0;
for (J = 0; J < 5; J++)
SUM += A[I].cal[J];
PRO = SUM / 5;
printf("\t\tPromedio: %.2f", PRO);
}
}

void F2(alumno A[], int T) {
int I;
printf("\nAlumnos con calificacion mayor a 9 en la tercera materia\n");
for (I = 0; I < T; I++)
if (A[I].cal[2] > 9)
printf("Matricula del alumno: %d\n", A[I].matricula);
}

void F3(alumno A[], int T) {
int I;
float SUM = 0.0;
for (I = 0; I < T; I++)
SUM += A[I].cal[3];
SUM /= T;
printf("\n\nPromedio de la cuarta materia: %.2f", SUM);
}
    