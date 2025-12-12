#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol {
    int dato;
    struct Arbol* izq;
    struct Arbol* der;
} Arbol;

Arbol* nuevoNodo(int v) {
    Arbol* n = (Arbol*)malloc(sizeof(Arbol));
    n->dato = v;
    n->izq = n->der = NULL;
    return n;
}

Arbol* insertar(Arbol* r, int v) {
    if (r == NULL) return nuevoNodo(v);

    if (v < r->dato)
        r->izq = insertar(r->izq, v);
    else
        r->der = insertar(r->der, v);

    return r;
}

void preOrden(Arbol* r) {
    if (!r) return;
    printf("%d ", r->dato);
    preOrden(r->izq);
    preOrden(r->der);
}

int main() {
    Arbol* raiz = NULL;
    raiz = insertar(raiz, 15);
    raiz = insertar(raiz, 7);
    raiz = insertar(raiz, 22);
    raiz = insertar(raiz, 10);

    preOrden(raiz);
    return 0;
}
