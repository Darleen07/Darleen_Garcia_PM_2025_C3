#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int destino;
    struct Nodo* sig;
} Nodo;

typedef struct {
    int vertices;
    Nodo** lista;
} Grafo;

Nodo* crearNodo(int d) {
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    n->destino = d;
    n->sig = NULL;
    return n;
}

Grafo* crearGrafo(int v) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->vertices = v;
    g->lista = (Nodo**)malloc(v * sizeof(Nodo*));

    for (int i = 0; i < v; i++)
        g->lista[i] = NULL;

    return g;
}

void conectar(Grafo* g, int a, int b) {
    Nodo* n = crearNodo(b);
    n->sig = g->lista[a];
    g->lista[a] = n;
}

void mostrarGrafo(Grafo* g) {
    for (int i = 0; i < g->vertices; i++) {
        Nodo* temp = g->lista[i];
        printf("Vecinos de %d: ", i);
        while (temp) {
            printf("%d ", temp->destino);
            temp = temp->sig;
        }
        printf("\n");
    }
}

int main() {
    Grafo* g = crearGrafo(5);

    conectar(g, 0, 3);
    conectar(g, 1, 4);
    conectar(g, 3, 2);

    mostrarGrafo(g);
    return 0;
}
