#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

time_t *threads_last_entry;
time_t *threads_max_wait_time;

time_t start_time;


void printStatus(int thread_id){
    if(thread_id == -1){
        printf("ReaderQ: %d WriterQ: %d [in: R:%d W:%d]\n", 
            que.readers, que.writers, lib.readers, lib.writers);
        fflush(stdout);
        return;
    }

    char who[7] = "READER";
    if(thread_id > readers_num){
        strcpy(who, "WRITER");
    }

    printf("ReaderQ: %d WriterQ: %d [in: R:%d W:%d] - %s ID %d\n", 
            que.readers, que.writers, lib.readers, lib.writers, who, thread_id);
    fflush(stdout);
}

void signalHandler(){
    time_t end_time = time(NULL);
    time_t process_time = end_time - start_time;
    char thr_type[7] = "READER";
    
    pthread_mutex_lock(&lock);
    printf("\n\nProcess time: %lds\n\n", process_time);
    for(int i = 0; i < readers_num + writers_num; i++){
        if(i == readers_num){
            strcpy(thr_type, "WRITER");
        }
        time_t d_time = end_time - threads_last_entry[i];
        if(threads_max_wait_time[i] < d_time){
            threads_max_wait_time[i] = d_time;
        }

        float percentage = ((float)threads_max_wait_time[i] / (float)process_time) * (float)100;

        printf("[%3d] %s longest time in queue: %3lds   -   %6.2f%%\n", i, thr_type, threads_max_wait_time[i], percentage);
    }
    exit(0);
} 