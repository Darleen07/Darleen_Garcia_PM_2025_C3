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
Libro* cargarDesdeArchivo(char *nombreArchivo);
void guardarEnArchivo(char *nombreArchivo, Libro *lista);
Libro* agregarLibro(Libro *lista);
void mostrarLista(Libro *lista);
void buscarPorTitulo(Libro *lista, char *titulo);
void buscarPorAutor(Libro *lista, char *autor);

// ---------------------------------------------------------

int main() {
    Libro *lista = NULL;
    char archivo[] = "libros.dat";
    int opcion;
    char buscar[100];

    // Cargar libros desde archivo
    lista = cargarDesdeArchivo(archivo);

    do {
        printf("\n==== MENU ====\n");
        printf("1. Agregar libro\n");
        printf("2. Buscar por titulo\n");
        printf("3. Buscar por autor\n");
        printf("4. Mostrar lista\n");
        printf("5. Guardar y salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch(opcion) {
            case 1:
                lista = agregarLibro(lista);
                break;

            case 2:
                printf("Titulo a buscar: ");
                fgets(buscar, 100, stdin);
                buscar[strcspn(buscar, "\n")] = '\0';
                buscarPorTitulo(lista, buscar);
                break;

            case 3:
                printf("Autor a buscar: ");
                fgets(buscar, 100, stdin);
                buscar[strcspn(buscar, "\n")] = '\0';
                buscarPorAutor(lista, buscar);
                break;

            case 4:
                mostrarLista(lista);
                break;

            case 5:
                guardarEnArchivo(archivo, lista);
                printf("Datos guardados correctamente.\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }

    } while(opcion != 5);

    return 0;
}

// ---------------------------------------------------------
// Cargar lista desde archivo
Libro* cargarDesdeArchivo(char *nombreArchivo) {
    FILE *f = fopen(nombreArchivo, "rb");
    if (!f) {
        printf("Archivo no encontrado, se crea una lista nueva.\n");
        return NULL;
    }

    Libro temp;
    Libro *lista = NULL, *nuevo, *ultimo = NULL;

    while (fread(&temp, sizeof(Libro) - sizeof(Libro*), 1, f)) {
        nuevo = (Libro*) malloc(sizeof(Libro));
        *nuevo = temp;
        nuevo->siguiente = NULL;

        if (!lista)
            lista = nuevo;
        else
            ultimo->siguiente = nuevo;

        ultimo = nuevo;
    }

    fclose(f);
    return lista;
}

// ---------------------------------------------------------
// Guardar lista en archivo
void guardarEnArchivo(char *nombreArchivo, Libro *lista) {
    FILE *f = fopen(nombreArchivo, "wb");
    if (!f) {
        printf("No se pudo guardar el archivo.\n");
        return;
    }

    Libro *actual = lista;

    while (actual) {
        fwrite(actual, sizeof(Libro) - sizeof(Libro*), 1, f);
        actual = actual->siguiente;
    }

    fclose(f);
}

// ---------------------------------------------------------
// Agregar libro a lista
Libro* agregarLibro(Libro *lista) {
    Libro *nuevo = (Libro*) malloc(sizeof(Libro));
    nuevo->siguiente = NULL;

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
    getchar(); // limpiar buffer

    // Insertar al inicio de la lista
    nuevo->siguiente = lista;

    printf("Libro agregado correctamente.\n");

    return nuevo;
}

// ---------------------------------------------------------
void mostrarLista(Libro *lista) {
    Libro *actual = lista;

    while (actual) {
        printf("\n--- Libro ---\n");
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
void buscarPorTitulo(Libro *lista, char *titulo) {
    Libro *actual = lista;
    int encontrado = 0;

    while (actual) {
        if (strcasecmp(actual->titulo, titulo) == 0) {
            printf("\n>> Coincidencia encontrada:\n");
            printf("Autor: %s\n", actual->autor);
            printf("Ano: %d\n", actual->ano);
            printf("Precio: %.2f\n", actual->precio);
            printf("Codigo: %d\n", actual->codigo);
            printf("Descripcion: %s\n", actual->descripcion);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }

    if (!encontrado)
        printf("No se encontraron libros con ese titulo.\n");
}

// ---------------------------------------------------------
void buscarPorAutor(Libro *lista, char *autor) {
    Libro *actual = lista;
    int encontrado = 0;

    while (actual) {
        if (strcasecmp(actual->autor, autor) == 0) {
            printf("\n>> Coincidencia encontrada:\n");
            printf("Titulo: %s\n", actual->titulo);
            printf("Ano: %d\n", actual->ano);
            printf("Precio: %.2f\n", actual->precio);
            printf("Codigo: %d\n", actual->codigo);
            printf("Descripcion: %s\n", actual->descripcion);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }

    if (!encontrado)
        printf("No se encontraron libros de ese autor.\n");
}

