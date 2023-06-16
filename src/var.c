#include <pthread.h>
#include <stdbool.h>

unsigned int MAX_TIME;
unsigned int REST_TIME;

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

Library lib;
Queue   que;

pthread_mutex_t lock         = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  readers_lock = PTHREAD_COND_INITIALIZER;
pthread_cond_t  writers_lock = PTHREAD_COND_INITIALIZER;

unsigned int writers_counter;

unsigned int readers_num;
unsigned int writers_num;

time_t *threads_last_entry;
time_t *threads_max_wait_time;

time_t start_time;
