#include <stdio.h>
#include <stdlib.h>

/* Suma reales.
El programa lee cadenas de caracteres de un archivo, detecta aquellas que
comienzan con números, los suma y calcula el promedio de los mismos. */

void sumypro(FILE *); /* Prototipo de función. */

int main(void) /* Cambiado de void main(void) a int main(void) */
{
    FILE *ap;
    if ((ap = fopen("C:\\Users\\sv988\\Desktop\\programacion 2\\Tarea #6\\Capitulo #9\\programa RP9.5\\bin\\Debug\\arc2.txt", "r")) != NULL)
    {
        sumypro(ap);
        /* Se llama a la función sumypro. Se pasa el archivo ap como parámetro. */
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}

void sumypro(FILE *ap1)
/* Esta función lee cadenas de caracteres de un archivo, detecta aquellas
que comienzan con números, y obtiene la suma y el promedio de dichos
números. */
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;

    /* La función fgets y el uso de feof en el bucle pueden tener problemas
    para leer la última línea si termina sin salto de línea. Se mantiene
    el código original, pero se recomienda el patrón de lectura
    "while (fgets(...) != NULL)" para archivos. */
    while (!feof (ap1))
    {
        fgets(cad, 30, ap1); /* Se lee la cadena del archivo. */

        /* Si fgets falla al leer (por fin de archivo o error), y luego se
        llama a feof, puede haber un comportamiento inesperado.
        Una verificación simple es: */
        if (feof(ap1) && cad[0] == '\0')
        {
            break;
        }

        r = atof(cad);

        /* Recuerda que la función atof convierte una cadena de caracteres que
        contiene números reales a un valor de tipo double. Si la cadena comienza
        con otro caracter o no contiene números, regresa 0. */
        if (r != 0.0) /* Usamos r != 0.0 para ser más claros, ya que 0 es el valor de retorno por defecto si no es un número. */
        {
            i++;
            sum += r;
        }
        /* Nota: Si la línea contiene el número 0.0, será contado y sumado,
        pero si la línea no contiene números, también será evaluado como 0.0.
        Para un chequeo más estricto si la cadena empieza con un dígito
        se usaría isdigit(cad[0]). */
    }

    printf("\nSuma: %.2f", sum);
    if (i) /* Si el valor de i es distinto de cero, calcula el promedio. */
    {
        printf("\nPromedio: %.2f", sum / i);
    }
}
