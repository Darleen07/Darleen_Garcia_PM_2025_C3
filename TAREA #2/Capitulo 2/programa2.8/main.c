#include <stdio.h>

/* Asistentes.
E programa, al recibir como datos la maatrícula, la carrera, el semestre
y el promedio de un alumno de una universidad privasda, determina si
éste puede ser asistente de su carrera.

MAT, CAR Y SEM: variables de tipo entero
PRO: variable de tipo real. */

void main(void)
{
    int MAT, CAR, SEM;
    float PRO;
    printf("Ingrese matricula: ");
    scanf("%d" , &MAT);
    printf("Ingrese carrera (1-Industia 2-Telemática 3-Computación 4-Mecánica) : ");
    scanf("%d" , &CAR);
    printf("Ingrese semestre: ");
    scanf("%d", &SEM );
    printf("Ingrese promedio: ");
    scanf("%f", &PRO);
    switch(CAR)
    {
        case 1: if (SEM >= 6 && PRO >= 8.5)
                    printf("\n%d %d %5.2f", MAT, CAR, PRO);
                    break;
        case 2: if (SEM >= 5 && PRO >= 9.0)
                    printf("\n%d %d %5.2f", MAT, CAR, PRO);
                    break;
        case 3: if (SEM >= 6 && PRO >= 8.8)
                    printf("\n%d %d %5.2f",MAT, CAR, PRO);
                    break;
        case 4: if (SEM >= 7 && PRO >= 9.0)
                    printf("\n%d %d %5.2f", MAT, CAR, PRO);
                    break;
                  default: printf("\n Error en la carrera" );
                    break;

    }

}
