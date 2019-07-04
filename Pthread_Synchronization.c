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
    if (NUMINIT != pthread_mutex_init(&lock, NULL))
    {
        fprintf(stdout, "\nMutex init has failed\n");
        exit(NUMINIT + 1);
    }
    #endif
    if(validateCommandInput(argv, argc, &convert))
    {
        srand (time(NULL));
        #ifdef PTHREAD_SYNC
        if(NUMINIT != pthread_barrier_init(&barrier, NULL, convert))
        {
            fprintf(stdout, "\nBarrier init has failed\n");
            exit(NUMINIT + 1);
        }
        #endif
        pthread_t threads[convert];
        for(iterator = NUMINIT; iterator < convert; iterator++)
        {
            if(NUMINIT != pthread_create(&threads[iterator], NULL, threadFunction, (void *)iterator))
            {
                fprintf(stderr, "\nThread creation has failed\n");
                exit(NUMINIT + 1);
            }
        }
        for(iterator = NUMINIT; iterator < convert; iterator++)
        {
            if(NUMINIT != pthread_join(threads[iterator], NULL))
            {
                fprintf(stderr, "\nThread join has failed\n");
                exit(NUMINIT + 1);
            }
        }
    }
    else
    {
        message = "\nInvalid input\n";
        fprintf(stderr, "%s\n", message);
        return NUMINIT + 1;
    }
    #ifdef PTHREAD_SYNC
    if(NUMINIT != pthread_mutex_destroy(&lock))
    {
        fprintf(stderr, "\nMutex creation has failed\n");
        exit(NUMINIT + 1);
    }
    if(NUMINIT != pthread_barrier_destroy(&barrier))
    {
        fprintf(stderr, "\nThread creation has failed\n");
        exit(NUMINIT + 1);
    }
    #endif
    return NUMINIT;
}

bool validateCommandInput(int inputLength, const char * input[], long int * convert)
{
    bool valid = false;
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
        if(NUMINIT != pthread_mutex_lock(&lock))
        {
            fprintf(stdout, "\nMutex lock has failed\n");
            exit(NUMINIT + 1);
        }
        #endif
        val = sharedVariable;
        fprintf(stdout, "*** thread %ld sees value %d\n", threadID, val);
        sharedVariable = val + 1;
        #ifdef PTHREAD_SYNC
        if(NUMINIT != pthread_mutex_unlock(&lock))
        {
            fprintf(stdout, "\nMutex unlock has failed\n");
            exit(NUMINIT + 1);
        }
        #endif
    }
    #ifdef PTHREAD_SYNC
    pthread_barrier_wait(&barrier);
    #endif
    val = sharedVariable;
    fprintf(stdout, "Thread %ld sees final value %d\n", threadID, val);
}

void * threadFunction(void * threadID)
{
    long int tID = NUMINIT;
    tID = (long int) threadID;
    simpleThread(tID);
    return threadID;
}
