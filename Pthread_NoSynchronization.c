#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#define NUMINIT 0
typedef enum {false, true} bool;
int sharedVariable = NUMINIT;
bool validateCommandInput(int, const char * [], long int *);
void simpleThread(int threadID);
void * threadFunction(void * arg);

int main(int argv, const char * argc[])
{
    char * message;
    long int convert = NUMINIT;
    long int iterator = NUMINIT;
    if(validateCommandInput(argv, argc, &convert))
    {
        pthread_t threads[convert];
        for(iterator = NUMINIT; iterator < convert; iterator++)
        {
            pthread_create(&threads[iterator], NULL, threadFunction, NULL);
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
    }
    return NUMINIT;
}

bool validateCommandInput(int inputLength, const char * input[], long int * convert)
{
    bool isInt = false;
    char * endPoint;
    if(inputLength > 1)
    {
        *convert = atol(input[NUMINIT + 1]);
        if(NUMINIT != *convert)
        {
            isInt++;
        }
    }
    return isInt;
}

void simpleThread(int threadID)
{
    int num, val = NUMINIT;
    for(num = NUMINIT; num < 20; num++)
    {
        if (rand() > RAND_MAX / 2)
        {
            usleep(10);
        }
        val = sharedVariable;
        printf("*** thread %d sees value %d\n", threadID, val);
        sharedVariable = val + 1;
    }
    val = sharedVariable;
    printf("Thread %d sees final value %d\n", threadID, val);
}

void * threadFunction()
{
    pthread_t threadID = pthread_self();
    simpleThread((int)threadID);
    return (void *) NUMINIT;
}
