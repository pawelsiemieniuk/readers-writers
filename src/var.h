#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef VAR
#define VAR

#define MAX_TIME    2
#define REST_TIME   1

typedef struct Library
{
    unsigned int readers;
    unsigned int writers;
}Library;

// Tymczasowo tablica, zamienic na liste
//pthread_t *thr_id;
extern pthread_t thr_id[5];
extern Library lib;
extern pthread_mutex_t lock;



#endif