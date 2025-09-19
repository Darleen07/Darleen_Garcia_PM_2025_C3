#include <stdio.h>

int main(void)
{
    float costo, dinero, cambio;

    printf("Ingrese el costo del articulo: ");
    scanf("%f", &costo);
    printf("Ingrese el dinero entregado: ");
    scanf("%f", &dinero);

    cambio = dinero - costo;

    printf("\nEl cambio a devolver es: %.2f\n", cambio);

    return 0;
}
