#include <stdio.h>

#define MAX 40

int cola[MAX];
int inicio = 0, fin = 0, cantidad = 0;

void insertar(int x) {
    cola[fin] = x;
    fin = (fin + 1) % MAX;
    cantidad++;
}

int atender() {
    int x = cola[inicio];
    inicio = (inicio + 1) % MAX;
    cantidad--;
    return x;
}

int main() {
    insertar(100);
    insertar(200);
    insertar(300);

    printf("Atendiendo: %d\n", atender());
    printf("Atendiendo: %d\n", atender());

    return 0;
}
