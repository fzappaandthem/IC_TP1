#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

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

int main()
{
    int entero = 1, retval ;
    pthread_t hilos[3];

    retval = pthread_create(&hilos[0], NULL, hilo_1, &entero);
    retval = pthread_create(&hilos[1], NULL, hilo_2, &entero);
    retval = pthread_create(&hilos[2], NULL, hilo_3, &entero);

    for ( int i = 0 ; i < 3 ; i++)
    {
        pthread_join(hilos[i], NULL);
    }

    printf("mi pid = %d (Proceso), y entero = %d, fin de experimento.\n", getpid(), entero);
    return EXIT_SUCCESS;
}