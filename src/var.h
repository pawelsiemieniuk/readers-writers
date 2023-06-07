#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef VAR
#define VAR


#define MAX_TIME    5
#define REST_TIME   2

typedef struct Library
{
    unsigned int readers;
    unsigned int writers;
}Library;

extern volatile Library lib;
extern pthread_mutex_t lock;

extern unsigned int readers_num;
extern unsigned int writers_num;


#endif