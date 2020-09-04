#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* Ejercicio 1
 
 * Escriba un programa llamado ej1.c que tenga un único contador y tres hilos para
 * modificar su valor. Uno de esos hilos, incrementa el contador en 2 en cada iteración y
 * muestra su valor en pantalla, mientras que los dos hilos restantes, lo decrementa en 1 y
 * muestra su valor en pantalla. Ejemplo “Hilo 1 incremento el contador al valor de 25”.

    Autor: Gastón Di Filippo
    Fecha: Viernes 04092020

 */

void *hilo_1(void * var_local)
{

    for(int i = 0 ; i < 100; i ++)
    {
        printf("Soy el hilo 1, de id: %d; incremento la variable a: %d\n", getpid(), (*(int*) var_local) += 2);
    }
    pthread_exit((void *)0);
}

void *hilo_2(void * var_local)
{
    for(int i = 0 ; i < 100; i ++)
    {
        
        printf("Soy el hilo 2, de id: %d; incremento la variable a: %d\n", getpid(), (*(int*) var_local) -= 1);
    }
    pthread_exit((void *)0);
}

void *hilo_3(void * var_local)
{
    for(int i = 0 ; i < 100; i ++)
    {
        
        printf("Soy el hilo 3, de id: %d; incremento la variable a: %d\n", getpid(), (*(int*) var_local) -= 1);
    }
    pthread_exit((void *)0);
}
