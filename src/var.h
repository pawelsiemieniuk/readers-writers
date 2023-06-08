#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>

#ifndef VAR
#define VAR


#define MAX_TIME    5
#define REST_TIME   1

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

extern volatile Library lib;
extern volatile Queue que;

extern pthread_mutex_t lock;
extern pthread_cond_t readers_lock;
extern pthread_cond_t writers_lock;

extern unsigned int readers_num;
extern unsigned int writers_num;

extern time_t *threads_last_entry;
extern time_t *threads_max_wait_time;

extern time_t start_time;


void printStatus(int thread_id);

void signalHandler();

#endif