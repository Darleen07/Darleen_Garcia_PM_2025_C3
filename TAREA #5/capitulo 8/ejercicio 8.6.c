#include <stdio.h>
#include <string.h>

typedef struct {
int clave;
char nombre[50];
float precio;
int existencia;
} producto;

void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

int main(void) {
producto INV[100];
int TAM, OPE;
do {
printf("Ingrese el nmero de productos: ");
scanf("%d", &TAM);
} while (TAM > 100 || TAM < 1);
Lectura(INV, TAM);
printf("\nIngrese operacin a realizar.\n\t\t1  Ventas\n\t\t2  Reabastecimiento\n\t\t3 - Nuevos Productos\n\t\t4  Inventario\n\t\t0 - Salir: ");
scanf("%d", &OPE);
while (OPE) {
switch (OPE) {
case 1: Ventas(INV, TAM); break;
case 2: Reabastecimiento(INV, TAM); break;
case 3: Nuevos_Productos(INV, &TAM); break;
case 4: Inventario(INV, TAM); break;
}
printf("\nIngrese operacin a realizar.\n\t\t1  Ventas\n\t\t2  Reabastecimiento\n\t\t3 - Nuevos Productos\n\t\t4  Inventario\n\t\t0 - Salir: ");
scanf("%d", &OPE);
}
return 0;
}

void Lectura(producto A[], int T) {
int I;
for (I = 0; I < T; I++) {
printf("\nIngrese informacin del producto %d\n", I + 1);
printf("\tClave: ");
scanf("%d", &A[I].clave);
fflush(stdin);
printf("\tNombre: ");
gets(A[I].nombre);
printf("\tPrecio: ");
scanf("%f", &A[I].precio);
printf("\tExistencia: ");
scanf("%d", &A[I].existencia);
}
}

void Ventas(producto A[], int T) {
int CLA, CAN, I;
float TOT = 0.0, PAR;
printf("\nIngrese clave del producto -0 para salir-: ");
scanf("%d", &CLA);
while (CLA) {
printf("\tCantidad: ");
scanf("%d", &CAN);
I = 0;
while (I < T && A[I].clave < CLA)
I++;
if (I == T || A[I].clave > CLA)
printf("\nLa clave del producto es incorrecta\n");
else if (A[I].existencia >= CAN) {
A[I].existencia -= CAN;
PAR = A[I].precio * CAN;
printf("\tImporte: %.2f\n", PAR);
TOT += PAR;
} else
printf("\nNo existe en inventario la cantidad solicitada. Slo hay %d\n", A[I].existencia);
printf("\nIngrese la siguiente clave del producto -0 para salir-: ");
scanf("%d", &CLA);
}
printf("\nTotal de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T) {
int CLA, CAN, I;
printf("\nIngrese clave del producto -0 para salir-: ");
scanf("%d", &CLA);
while (CLA) {
I = 0;
while (I < T && A[I].clave < CLA)
I++;
if (I == T || A[I].clave > CLA)
printf("\nLa clave del producto ingresada es incorrecta\n");
else {
printf("\tCantidad: ");
scanf("%d", &CAN);
A[I].existencia += CAN;
}
printf("\nIngrese otra clave del producto -0 para salir-: ");
scanf("%d", &CLA);
}
}

void Nuevos_Productos(producto A[], int *T) {
int CLA, I, J;
printf("\nIngrese clave del producto -0 para salir-: ");
scanf("%d", &CLA);
while (*T < 100 && CLA) {
I = 0;
while (I < *T && A[I].clave < CLA)
I++;
if (I == *T) {
A[I].clave = CLA;
printf("\tNombre: ");
fflush(stdin);
gets(A[I].nombre);
printf("\tPrecio: ");
scanf("%f", &A[I].precio);
printf("\tCantidad: ");
scanf("%d", &A[I].existencia);
*T = *T + 1;
} else if (A[I].clave == CLA)
printf("\nEl producto ya se encuentra en el inventario\n");
else {
for (J = *T; J > I; J--)
A[J] = A[J - 1];
A[I].clave = CLA;
printf("\tNombre: ");
fflush(stdin);
gets(A[I].nombre);
printf("\tPrecio: ");
scanf("%f", &A[I].precio);
printf("\tCantidad: ");
scanf("%d", &A[I].existencia);
*T = *T + 1;
}
printf("\nIngrese otra clave de producto -0 para salir-: ");
scanf("%d", &CLA);
}
if (*T == 100)
printf("\nYa no hay espacio para incorporar nuevos productos\n");
}

void Inventario(producto A[], int T) {
int I;
for (I = 0; I < T; I++) {
printf("\nClave: %d", A[I].clave);
printf("\tNombre: %s", A[I].nombre);
printf("\tPrecio: %.2f", A[I].precio);
printf("\tExistencia: %d\n", A[I].existencia);
}
}

