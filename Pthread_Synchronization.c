/*
COP4610 – Principles of Operating Systems – Summer C 2019
Please use OpenMP directives and OpenMP synchronization primitives ONLY as
appropriate.

Prof. Jose F. Osorio
Student: Justin Danglade – 4552415
Project: Multithreaded Programming
Due Date: 07/8/2019 by 11:55pm
File Name: Pthread_Synchronization.c

I certify that this program code has been written by me
and no part of it has been taken from any sources.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>
#define NUMINIT 0
typedef enum {false, true} bool;

bool validateCommandInput(int, const char * [], long int *);
void simpleThread(long int threadID);
void * threadFunction(void * threadID);
int sharedVariable = NUMINIT;
#ifdef PTHREAD_SYNC
pthread_mutex_t lock;
pthread_barrier_t barrier;
#endif

int main(int argv, const char * argc[])
{
    char * message;
    long int convert = NUMINIT;
    long int iterator = NUMINIT;

    #ifdef PTHREAD_SYNC
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return NUMINIT + 1;
    }
    #endif
    if(validateCommandInput(argv, argc, &convert))
    {
        srand (time(NULL));
        #ifdef PTHREAD_SYNC
        pthread_barrier_init(&barrier, NULL, convert);
        #endif
        pthread_t threads[convert];
        for(iterator = NUMINIT; iterator < convert; iterator++)
        {
            pthread_create(&threads[iterator], NULL, threadFunction, (void *)iterator);
        }
        for(iterator = NUMINIT; iterator < convert; iterator++)
        {
            pthread_join(threads[iterator], NULL);
        }
    }
    else
    {
        message = "Invalid input";
        printf("%s\n", message);
        return NUMINIT + 1;
    }
    #ifdef PTHREAD_SYNC
    pthread_mutex_destroy(&lock);
    pthread_barrier_destroy(&barrier);
    #endif
    return NUMINIT;
}

bool validateCommandInput(int inputLength, const char * input[], long int * convert)
{
    bool valid = false;
    char * endPoint;
    if(inputLength == 2)
    {
        *convert = atol(input[NUMINIT + 1]);
        if(NUMINIT != *convert)
        {
            valid++;
        }
    }
    return valid;
}

void simpleThread(long threadID)
{
    int num, val = NUMINIT;
    for(num = NUMINIT; num < 20; num++)
    {
        if (rand() > RAND_MAX / 2)
        {
            usleep(10);
        }
        #ifdef PTHREAD_SYNC
        pthread_mutex_lock(&lock);
        #endif
        val = sharedVariable;
        printf("*** thread %ld sees value %d\n", threadID, val);
        sharedVariable = val + 1;
        #ifdef PTHREAD_SYNC
        pthread_mutex_unlock(&lock);
        #endif
    }
    #ifdef PTHREAD_SYNC
    pthread_barrier_wait(&barrier);
    #endif
    val = sharedVariable;
    printf("Thread %ld sees final value %d\n", threadID, val);
}

void * threadFunction(void * threadID)
{
    long int tID = NUMINIT;
    tID = (long int) threadID;
    simpleThread(tID);
    return threadID;
}
