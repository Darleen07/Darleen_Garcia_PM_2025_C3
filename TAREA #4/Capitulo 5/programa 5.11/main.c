#include <stdio.h>

/* B�squeda binaria. */
const int MAX = 100;
void Lectura(int A[], int T);                   /* Prototipos de funciones. */
int Binaria(int A[], int T, int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);
    /* Se verifica que el tama�o del arreglo sea correcto. */

    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);
    /* Se llama a la funci�n que busca en el arreglo. */

    if (RES)
        printf("\nEl elemento se encuentra en la posicion: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* La funci�n Lectura se utiliza para leer un arreglo unidimensional de T
   elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
/* Esta funci�n se utiliza para realizar una busqueda binaria del
   elemento E en el arreglo unidimensional A de T elementos. Si se
   encuentra el elemento, regresa la posicion correspondiente.
   En caso contrario, regresa 0. */
{
    int IZQ = 0, DER = T - 1, CEN, POS = 0;

    while (IZQ <= DER && !POS)
    {
        CEN = (IZQ + DER) / 2;
        if (A[CEN] == E)
            POS = CEN + 1;  /* Ajuste para que las posiciones comiencen en 1 */
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return POS;
}
