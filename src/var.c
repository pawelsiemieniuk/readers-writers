#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Library
{
    unsigned int readers;
    unsigned int writers;
}Library;

typedef struct Queue
{
    unsigned int readers;
    unsigned int writers;
}Queue;

volatile Library lib;
volatile Queue que;

pthread_mutex_t lock        = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t readers_lock = PTHREAD_COND_INITIALIZER;
pthread_cond_t writers_lock = PTHREAD_COND_INITIALIZER;

unsigned int readers_num;
unsigned int writers_num;



void printStatus(int thread_id){
    if(thread_id == -1){
        printf("ReaderQ: %2d WriterQ: %2d [in: R: %2d W: %2d]\n", 
            que.readers, que.writers, lib.readers, lib.writers);
        fflush(stdout);
        return;
    }

    char who[7] = "READER";
    if(thread_id >= readers_num){
        strcpy(who, "WRITER");
    }

    printf("ReaderQ: %2d WriterQ: %2d [in: R: %2d W: %2d] - %s ID %3d\n", 
            que.readers, que.writers, lib.readers, lib.writers, who, thread_id);
    fflush(stdout);
}