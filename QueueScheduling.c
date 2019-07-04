/*
COP4610 – Principles of Operating Systems – Summer C 2019
Please use OpenMP directives and OpenMP synchronization primitives ONLY as
appropriate.

Prof. Jose F. Osorio
Student: Justin Danglade – 4552415
Project: Multithreaded Programming
Due Date: 07/8/2019 by 11:55pm
File Name: QueueScheduling.c

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

bool validateCommandInput(int, const char * [], long int *, long int *);
void officeHours(int, const char * [], long int *, long int *);
void professor();
void answerStart();
void answerDone();
void student(int id);
void enterOffice();
void questionStart();
void questionDone();
void leaveOffice();
pthread_mutex_t lock;

int main(int argc, const char * argv[])
{
    char * message;
    long int argOne = NUMINIT;
    long int argTwo = NUMINIT;
    long int iterator = NUMINIT;
    if(validateCommandInput(argc, argv, &argOne, &argTwo))
    {
        officeHours(argc, argv, &argOne, &argTwo);
    }
    else
    {
        message = "Invalid input";
        fprintf(stderr, "%s\n", message);
        return NUMINIT + 1;
    }
    return NUMINIT;
}

bool validateCommandInput(int inputLength, const char * input[], long int * argOne, long int * argTwo)
{
    bool valid = false;
    char * endPoint;
    if(inputLength == 3)
    {
        *argOne = atol(input[NUMINIT + 1]);
        *argTwo = atol(input[NUMINIT + 2]);
        if((NUMINIT != *argOne) && (NUMINIT != *argTwo))
        {
            valid++;
        }
    }
    return valid;
}

void officeHours(int, const char * [], long int *, long int *)
{

}
