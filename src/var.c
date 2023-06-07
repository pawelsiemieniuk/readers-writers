#include <pthread.h>
#include <stdbool.h>

typedef struct Library
{
    unsigned int readers;
    unsigned int writers;
}Library;

volatile Library lib;
pthread_mutex_t lock;

unsigned int readers_num;
unsigned int writers_num;