#include <pthread.h>
#include <stdbool.h>

//#define MAX_TIME    2
//#define REST_TIME   1

typedef struct Library
{
    unsigned int readers;
    unsigned int writers;
}Library;


// Tymczasowo tablica, zamienic na liste
//pthread_t *thr_id;
pthread_t thr_id[5];
Library lib;
pthread_mutex_t lock;
