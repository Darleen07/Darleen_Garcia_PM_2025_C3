#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(int x) {
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    n->valor = x;
    n->siguiente = NULL;
    return n;
}

void agregarFinal(Nodo** inicio, int x) {
    Nodo* nuevo = crearNodo(x);
    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }
    Nodo* temp = *inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;
    temp->siguiente = nuevo;
}

void mostrar(Nodo* inicio) {
    printf("Lista: ");
    while (inicio) {
        printf("[%d] ", inicio->valor);
        inicio = inicio->siguiente;
    }
    printf("\n");
}

int main() {
    Nodo* lista = NULL;
    agregarFinal(&lista, 4);
    agregarFinal(&lista, 9);
    agregarFinal(&lista, 12);

    mostrar(lista);
    return 0;
}
