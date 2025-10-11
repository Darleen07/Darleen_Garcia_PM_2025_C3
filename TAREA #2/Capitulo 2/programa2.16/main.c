#include <stdio.h>

/* Empresa textil.
El programa, al recibir como datos decisivos la categoría y antiguedad de un empleado,
determina si es ek mismo reúne las condiciones establecisas por la empresa para ocupar un
nuevo cargo en un sucursal.

CLA, CAT, ANT, RES: variables de tipo entero;
SAL: variable de tipon real. */

void main(void)
{
    int CLA, CAT, ANT, RES;
    printf("\nIngrese la clave, categoria y antiguedad del trabajafdor:");
    scanf("%d %d %d", &CLA, &CAT, &ANT);
    switch (CAT)
    {
    case 3:
    case 4: if (ANT >= 5)
                RES = 1;
              else
                    RES = 0;
              break;
    case 2: if (ANT >= 7)
                    RES = 1;
            else
                        RES = 0;
            break;
        default: RES = 0;
            break;

    }
    if (RES)
        printf("\nEl trabajador con clave %d reúne las credenciales parta el puesto", CLA);
    else
        printf("\nEl trabajador con clave %d no reúne ls creden ciales para el puesto", CLA);
}
