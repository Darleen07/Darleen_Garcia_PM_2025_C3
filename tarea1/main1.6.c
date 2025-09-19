#include <stdio.h>

int main(void)
{
    float base, altura, area, perimetro;

    printf("Ingrese la base y la altura del rectangulo: ");
    scanf("%f %f", &base, &altura);

    area = base * altura;
    perimetro = 2 * (base + altura);

    printf("\nEl area del rectangulo es: %.2f", area);
    printf("\nEl perimetro del rectangulo es: %.2f\n", perimetro);

    return 0;
}
