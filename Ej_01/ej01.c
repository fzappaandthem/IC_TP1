#include "ej01.h"

/* Ejercicio 1
 
 * Escriba un programa llamado ej1.c que tenga un único contador y tres hilos para
 * modificar su valor. Uno de esos hilos, incrementa el contador en 2 en cada iteración y
 * muestra su valor en pantalla, mientras que los dos hilos restantes, lo decrementa en 1 y
 * muestra su valor en pantalla. Ejemplo “Hilo 1 incremento el contador al valor de 25”.

    Autor: Gastón Di Filippo
    Fecha: Viernes 04092020

 */

int main()
{
    int entero = 1, retval ;
    pthread_t hilos[3];
    printf("Inicializo el 'entero' con el valor de %d\n", entero);
    retval = pthread_create(&hilos[0], NULL, hilo_1, &entero);
    retval = pthread_create(&hilos[1], NULL, hilo_2, &entero);
    retval = pthread_create(&hilos[2], NULL, hilo_3, &entero);

    for ( int i = 0 ; i < 3 ; i++)
    {
        pthread_join(hilos[i], NULL);
    }

    printf("Soy el proceso #%d; el valor final de entero = %d, fin de experimento.\n", getpid(), entero);
    return EXIT_SUCCESS;
}