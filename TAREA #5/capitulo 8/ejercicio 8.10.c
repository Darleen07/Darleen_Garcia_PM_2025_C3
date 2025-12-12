#include <stdio.h>
#include <string.h>

typedef struct {
char noba[50];
char nucu[20];
} banco;

typedef union {
banco che;
banco nomi;
char venta;
} fpago;

typedef struct {
char cnu[50];
char col[50];
char cp[10];
char ciu[50];
} domicilio;

typedef struct {
int num;
char nom[50];
float ven[12];
domicilio domi;
float sal;
fpago pago;
int cla;
} vendedor;

void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

int main(void) {
vendedor VENDEDORES[100];
int TAM;
do {
printf("Ingrese el numero de vendedores: ");
scanf("%d", &TAM);
} while (TAM > 100 || TAM < 1);
Lectura(VENDEDORES, TAM);
F1(VENDEDORES, TAM);
F2(VENDEDORES, TAM);
F3(VENDEDORES, TAM);
F4(VENDEDORES, TAM);
printf("\n\tFIN DEL PROGRAMA\n");
return 0;
}

void Lectura(vendedor A[], int T) {
int I, J;
for (I = 0; I < T; I++) {
printf("\n\nIngrese datos del vendedor %d\n", I + 1);
printf("Numero de empleado: ");
scanf("%d", &A[I].num);
fflush(stdin);
printf("Nombre del empleado: ");
gets(A[I].nom);
for (J = 0; J < 12; J++) {
printf("Ventas del mes %d: ", J + 1);
scanf("%f", &A[I].ven[J]);
}
printf("Domicilio del empleado\n");
printf("\tCalle y numero: ");
gets(A[I].domi.cnu);
printf("\tColonia: ");
gets(A[I].domi.col);
printf("\tCodigo Postal: ");
gets(A[I].domi.cp);
printf("\tCiudad: ");
gets(A[I].domi.ciu);
printf("Salario: ");
scanf("%f", &A[I].sal);
printf("Clave Forma de Pago (1-Cheque 2-Nomina 3-Ventanilla): ");
scanf("%d", &A[I].cla);
fflush(stdin);
switch (A[I].cla) {
case 1:
printf("\tNombre del banco: ");
gets(A[I].pago.che.noba);
printf("\tNumero de cuenta: ");
gets(A[I].pago.che.nucu);
break;
case 2:
printf("\tNombre del banco: ");
gets(A[I].pago.nomi.noba);
printf("\tNumero de cuenta: ");
gets(A[I].pago.nomi.nucu);
break;
case 3:
A[I].pago.venta = 'S';
break;
}
}
}

void F1(vendedor A[], int T) {
int I, J;
float SUM;
printf("\n\t\tVentas Totales de los Vendedores\n");
for (I = 0; I < T; I++) {
SUM = 0.0;
for (J = 0; J < 12; J++)
SUM += A[I].ven[J];
printf("Numero de empleado: %d\nNombre: %s\nVentas: %.2f\n", A[I].num, A[I].nom, SUM);
}
}

void F2(vendedor A[], int T) {
int I, J;
float SUM;
printf("\n\t\tIncremento de Salarios a Vendedores\n");
for (I = 0; I < T; I++) {
SUM = 0.0;
for (J = 0; J < 12; J++)
SUM += A[I].ven[J];
if (SUM > 1500000.00) {
A[I].sal *= 1.05;
printf("Numero de empleado: %d\nNombre: %s\nVentas: %.2f\nNuevo Salario: %.2f\n", A[I].num, A[I].nom, SUM, A[I].sal);
}
}
}

void F3(vendedor A[], int T) {
int I, J;
float SUM;
printf("\n\t\tVendedores con Ventas < 300,000\n");
for (I = 0; I < T; I++) {
SUM = 0.0;
for (J = 0; J < 12; J++)
SUM += A[I].ven[J];
if (SUM < 300000.00)
printf("Numero de empleado: %d\nNombre: %s\nVentas: %.2f\n", A[I].num, A[I].nom, SUM);
}
}

void F4(vendedor A[], int T) {
int I;
printf("\n\t\tVendedores con Cuenta en el Banco\n");
for (I = 0; I < T; I++)
if (A[I].cla == 1)
printf("Numero de vendedor: %d\nBanco: %s\nCuenta: %s\n", A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
}
    