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
#include <time.h>
#include <pthread.h>
#define NUMINIT 0
typedef enum {false, true} bool;
struct student
{
	int id;
	int numQuestions;
	int questionNum;
	struct student *next;
};

bool validateCommandInput(int, const char * [], long int *, long int *);
void officeHours(long int *, long int *);
void professor();
void answerStart();
void answerDone();
void student(int id);
void enterOffice();
void questionStart();
void questionDone();
void leaveOffice();
void nap();

pthread_t professorThread;
struct student* studentIterator, listHead;
pthread_mutex_t sLock, pLock;
long int sCondition, pCondition = NUMINIT;
pthread_cond_t sConditional, profConditional;

int main(int argc, const char * argv[])
{
    char * message;
    long int argOne = NUMINIT;
    long int argTwo = NUMINIT;
    if(validateCommandInput(argc, argv, &argOne, &argTwo))
    {
        officeHours(&argOne, &argTwo);
    }
    else
    {
        message = "Invalid input\n";
        fprintf(stderr, "%s\n", message);
        return NUMINIT + 1;
    }
    return NUMINIT;
}

bool validateCommandInput(int inputLength, const char * input[], long int * argOne, long int * argTwo)
{
    bool valid = false;
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

void officeHours(long int * numOfStudents, long int * roomCapacity)
{
    /*

    pCondition = *numOfStudents;
    srand(time(NULL));
    int iterator;
    if(NUMINIT != pthread_create(&professorThread, NULL, (void *)professor, NULL))
    {
        fprintf(stderr, "\nThread creation has failed\n");
        exit(NUMINIT + 1);
    }
    for(iterator = NUMINIT; iterator < *numOfStudents; iterator++)
    {
        if(NUMINIT != pthread_create(&studentThreads[iterator], NULL, (void *)nap, NULL))
        {
            fprintf(stderr, "\nThread creation has failed\n");
            exit(NUMINIT + 1);
        }
        numOfQuestions[iterator] = rand() % 4 + 1;
    }
    for(iterator = NUMINIT; iterator < *numOfStudents; iterator++)
    {
        if(NUMINIT != pthread_join(studentThreads[iterator], NULL))
        {
            fprintf(stderr, "\nThread join has failed\n");
            exit(NUMINIT + 1);
        }
    }
    if(NUMINIT != pthread_join(professorThread, NULL))
    {
        fprintf(stderr, "\nThread join has failed\n");
        exit(NUMINIT + 1);
    }
    */
}

void professor()
{

}

void answerStart()
{
    if(NUMINIT == pCondition)
    {
        nap();
    }
    else
    {
        char * message = "Professor starts to answer question for student";
        fprintf("%s", message);
    }
}

void answerDone()
{

}

void student(int id)
{
    struct student * newstud =  malloc(sizeof(struct student));
    newstud->id = id + 1;
	newstud->numQuestions = rand() % 4 + 1;
	newstud->questionNum = 0;

}
void enterOffice()
{

}

void questionStart()
{

}

void questionDone()
{

}

void leaveOffice()
{

}

void nap()
{
    char * message = "Shh!... No students left, the professor is napping!";
    fprintf(stdout, "%s\n", message);
}
