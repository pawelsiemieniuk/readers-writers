#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Library
{
    unsigned int readers;
    unsigned int writers;
}Library;

volatile Library lib;
pthread_mutex_t lock;

unsigned int readers_num;
unsigned int writers_num;

unsigned int readers_queue;
unsigned int writers_queue;

void printStatus(int thread_id){
    if(!thread_id){
        printf("ReaderQ: %d WriterQ: %d [in: R:%d W:%d] - BEGINNING\n", 
            readers_queue, writers_queue, lib.readers, lib.writers);
        fflush(stdout);
        return;
    }

    char who[7] = "READER";
    if(thread_id > readers_num){
        strcpy(who, "WRITER");
    }
    
    printf("ReaderQ: %d WriterQ: %d [in: R:%d W:%d] - %s ID %d\n", 
            readers_queue, writers_queue, lib.readers, lib.writers, who, thread_id);
    fflush(stdout);
}