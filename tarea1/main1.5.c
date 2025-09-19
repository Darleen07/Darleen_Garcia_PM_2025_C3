#include <stdio.h>

int main(void)
{
    float base, altura, area;

    printf("Ingrese la base y la altura del triangulo: ");
    scanf("%f %f", &base, &altura);

    area = (base * altura) / 2;

    printf("\nEl area del triangulo es: %.2f\n", area);

    return 0;
}
