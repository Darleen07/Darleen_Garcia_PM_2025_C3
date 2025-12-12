#include <stdio.h>
#include <stdlib.h>

#define TAM 8

typedef struct Caja {
    int num;
    struct Caja* sig;
} Caja;

Caja* tabla[TAM] = {NULL};

int hash(int x) {
    return (x * 3 + 1) % TAM;
}

void insertar(int x) {
    int i = hash(x);

    Caja* c = (Caja*)malloc(sizeof(Caja));
    c->num = x;
    c->sig = tabla[i];
    tabla[i] = c;
}

int buscar(int x) {
    int i = hash(x);
    Caja* temp = tabla[i];

    while (temp) {
        if (temp->num == x) return 1;
        temp = temp->sig;
    }
    return 0;
}

void mostrar() {
    for (int i = 0; i < TAM; i++) {
        printf("%d: ", i);
        Caja* temp = tabla[i];
        while (temp) {
            printf("%d -> ", temp->num);
            temp = temp->sig;
        }
        printf("NULL\n");
    }
}

int main() {
    insertar(11);
    insertar(22);
    insertar(31);

    mostrar();

    printf("Buscando 22: %s\n", buscar(22) ? "Encontrado" : "No está");
    return 0;
}
