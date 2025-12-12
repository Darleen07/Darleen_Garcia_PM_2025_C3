#include <stdio.h>

/* Conflicto de variables con el mismo nombre (K). */

void f1(void); // Prototipo de función.
int K = 5;      // Variable global K.

void main(void)
{
    int I;
    // El bucle llama a f1() 3 veces.
    for (I = 1; I <= 3; I++) 
        f1();
}

void f1(void)
{
    // 1. Uso de K local.
    int K = 2;      // Variable local K.
    
    K += K;         // K local = 2 + 2 = 4
    
    printf("\nEl valor de la variable local es: %d", K);

    // 2. Acceso a K global y combinación.
    extern int K;   // Indica que la siguiente K es la global.
    
    // NOTA: El segundo 'K' a la derecha de la asignación *sí* se refiere a la K local.
    // Esto se debe a que la directiva 'extern' solo afecta el uso de 'K' a partir de su declaración.
    // Sin embargo, si el objetivo es sumar Global + Local, se debe hacer una *copia* del valor local.
    
    int K_local_val = 4; // Guardamos el valor final de la K local (4)
    
    K = K + K_local_val; // K global = K global actual + 4 (valor final de la local)
    
    printf("\nEl valor de la variable global es: %d", K); 
}