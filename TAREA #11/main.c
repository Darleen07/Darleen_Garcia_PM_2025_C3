#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Libro {
    char titulo[100];
    char autor[100];
    char descripcion[200];
    int ano;
    float precio;
    int codigo;
    struct Libro *siguiente;
} Libro;

// Prototipos
Libro* agregarLibro(Libro *lista);
void imprimirLista(Libro *lista);
void buscarPorAutor(Libro *lista, char *autor);
void ordenarPorPrecio(Libro **lista);

// ---------------------------------------------------------

int main() {
    Libro *lista = NULL;
    int opcion;
    char autorBuscado[100];

    do {
        printf("\n==== MENU ====\n");
        printf("1. Agregar libro\n");
        printf("2. Buscar por autor\n");
        printf("3. Ordenar lista por precio (BubbleSort)\n");
        printf("4. Imprimir lista completa\n");
        printf("5. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch(opcion) {

            case 1:
                lista = agregarLibro(lista);
                break;

            case 2:
                printf("Introduzca autor a buscar: ");
                fgets(autorBuscado, 100, stdin);
                autorBuscado[strcspn(autorBuscado, "\n")] = '\0';
                buscarPorAutor(lista, autorBuscado);
                break;

            case 3:
                ordenarPorPrecio(&lista);
                printf("Lista ordenada correctamente por precio.\n");
                break;

            case 4:
                imprimirLista(lista);
                break;

            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción no válida.\n");
        }

    } while(opcion != 5);

    return 0;
}

// ---------------------------------------------------------
// Agregar libro a la lista enlazada
Libro* agregarLibro(Libro *lista) {
    Libro *nuevo = (Libro*) malloc(sizeof(Libro));

    printf("Titulo: ");
    fgets(nuevo->titulo, 100, stdin);
    nuevo->titulo[strcspn(nuevo->titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(nuevo->autor, 100, stdin);
    nuevo->autor[strcspn(nuevo->autor, "\n")] = '\0';

    printf("Descripcion: ");
    fgets(nuevo->descripcion, 200, stdin);
    nuevo->descripcion[strcspn(nuevo->descripcion, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &nuevo->ano);

    printf("Precio: ");
    scanf("%f", &nuevo->precio);

    printf("Codigo: ");
    scanf("%d", &nuevo->codigo);
    getchar();

    nuevo->siguiente = lista;

    printf("Libro agregado correctamente.\n");
    return nuevo;
}

// ---------------------------------------------------------
// Imprimir lista completa
void imprimirLista(Libro *lista) {
    Libro *actual = lista;

    if (!actual) {
        printf("La lista está vacía.\n");
        return;
    }

    while (actual) {
        printf("\n=== LIBRO ===\n");
        printf("Titulo: %s\n", actual->titulo);
        printf("Autor: %s\n", actual->autor);
        printf("Ano: %d\n", actual->ano);
        printf("Precio: %.2f\n", actual->precio);
        printf("Codigo: %d\n", actual->codigo);
        printf("Descripcion: %s\n", actual->descripcion);

        actual = actual->siguiente;
    }
}

// ---------------------------------------------------------
// Búsqueda por autor
void buscarPorAutor(Libro *lista, char *autor) {
    Libro *actual = lista;
    int encontrado = 0;

    while (actual) {
        if (strcasecmp(actual->autor, autor) == 0) {
            printf("\n--- Coincidencia encontrada ---\n");
            printf("Titulo: %s\n", actual->titulo);
            printf("Ano: %d\n", actual->ano);
            printf("Precio: %.2f\n", actual->precio);
            printf("Codigo: %d\n", actual->codigo);
            printf("Descripcion: %s\n", actual->descripcion);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("No se encontraron libros del autor '%s'.\n", autor);
    }
}

// ---------------------------------------------------------
// Ordenar lista por precio usando Bubble Sort
void ordenarPorPrecio(Libro **lista) {
    if (*lista == NULL) return;

    int cambiado;
    Libro *actual;
    Libro *ultimo = NULL;

    do {
        cambiado = 0;
        actual = *lista;

        while (actual->siguiente != ultimo) {
            if (actual->precio > actual->siguiente->precio) {
                // intercambiar valores (no nodos)
                Libro temp = *actual;
                *actual = *(actual->siguiente);
                *(actual->siguiente) = temp;

                // Mantener punteros correctos
                Libro *aux = actual->siguiente->siguiente;
                actual->siguiente->siguiente = actual;
                actual->siguiente = aux;

                cambiado = 1;
            }
            actual = actual->siguiente;
        }

        ultimo = actual;

    } while (cambiado);
}
