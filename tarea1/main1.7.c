#include <stdio.h>
#include <math.h>

int main(void)
{
    float radio, area, circunf;
    const float PI = 3.141592;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    area = PI * pow(radio, 2);
    circunf = 2 * PI * radio;

    printf("\nEl area del circulo es: %.2f", area);
    printf("\nLa circunferencia del circulo es: %.2f\n", circunf);

    return 0;
}
