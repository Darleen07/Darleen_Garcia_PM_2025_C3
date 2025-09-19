#include <stdio.h>

int main(void)
{
    int i = 5, j, k;
    float x = 2.5, y;

    j = (i++ > 5) && (i < 8);
    printf("\nEl valor de j es: %d", j);

    k = (++i == 7) || (i > 10);
    printf("\nEl valor de k es: %d", k);

    y = (x += i) / 3;
    printf("\nEl valor de y es: %.2f\n", y);

    return 0;
}
