#include <stdio.h>
#include <string.h>

typedef struct {
char cal[50];
int num;
char col[50];
char cp[10];
char ciu[50];
} domicilio;

typedef struct {
char nom[50];
int edad;
char sexo;
int con;
domicilio dom;
char tel[20];
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
paciente HOSPITAL[50];
int TAM;
do {
printf("Ingrese el numero de pacientes: ");
scanf("%d", &TAM);
} while (TAM > 50 || TAM < 1);
Lectura(HOSPITAL, TAM);
F1(HOSPITAL, TAM);
F2(HOSPITAL, TAM);
F3(HOSPITAL, TAM);
return 0;
}

void Lectura(paciente A[], int T) {
int I;
for (I = 0; I < T; I++) {
printf("\n\nIngrese datos del paciente %d\n", I + 1);
printf("Nombre: ");
fflush(stdin);
gets(A[I].nom);
printf("Edad: ");
scanf("%d", &A[I].edad);
printf("Sexo (F-M): ");
fflush(stdin);
scanf("%c", &A[I].sexo);
printf("Condicion (1-5): ");
scanf("%d", &A[I].con);
fflush(stdin);
printf("\nCalle: ");
gets(A[I].dom.cal);
printf("Numero: ");
scanf("%d", &A[I].dom.num);
fflush(stdin);
printf("Colonia: ");
gets(A[I].dom.col);
printf("Codigo Postal: ");
gets(A[I].dom.cp);
printf("Ciudad: ");
gets(A[I].dom.ciu);
printf("Telefono: ");
gets(A[I].tel);
}
}

void F1(paciente A[], int T) {
int I, FEM = 0, MAS = 0;
for (I = 0; I < T; I++)
if (A[I].sexo == 'F')
FEM++;
else if (A[I].sexo == 'M')
MAS++;
printf("\n\nPorcentaje de Hombres: %.2f%%", (float)MAS / T * 100);
printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / T * 100);
}

void F2(paciente A[], int T) {
int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
for (I = 0; I < T; I++)
switch (A[I].con) {
case 1: C1++; break;
case 2: C2++; break;
case 3: C3++; break;
case 4: C4++; break;
case 5: C5++; break;
}
printf("\n\nNumero de pacientes en condicion 1: %d", C1);
printf("\nNumero de pacientes en condicion 2: %d", C2);
printf("\nNumero de pacientes en condicion 3: %d", C3);
printf("\nNumero de pacientes en condicion 4: %d", C4);
printf("\nNumero de pacientes en condicion 5: %d", C5);
}

void F3(paciente A[], int T) {
int I;
printf("\n\nPacientes con condicion de ingreso de maxima gravedad\n");
for (I = 0; I < T; I++)
if (A[I].con == 5) {
printf("Nombre: %s", A[I].nom);
printf("\tTelefono: %s\n", A[I].tel);
}
}
        