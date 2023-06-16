#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include "func.h"

#ifndef VAR
#define VAR

extern unsigned int MAX_TIME;
extern unsigned int REST_TIME;

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

extern Library lib;
extern Queue   que;

extern pthread_mutex_t  lock;
extern pthread_cond_t   readers_lock;
extern pthread_cond_t   writers_lock;

// Zlicza ilu pisarzy mialo dostep do biblioteki w jednym cyklu (wykluczenie zaglodzenia)
extern unsigned int writers_counter;

extern unsigned int readers_num;
extern unsigned int writers_num;

extern time_t *threads_last_entry;
extern time_t *threads_max_wait_time;

extern time_t start_time;

#endif
