#include <stdio.h>

#define LIM 50

int pila[LIM];
int tope = 0;

void meter(int x) {
    pila[tope++] = x;
}

int sacar() {
    return pila[--tope];
}

int verTope() {
    return pila[tope - 1];
}

int main() {
    meter(3);
    meter(8);
    meter(12);

    printf("Tope actual: %d\n", verTope());
    printf("Sacado: %d\n", sacar());

    return 0;
}
