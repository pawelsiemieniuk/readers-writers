#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_TIME_IN_LIB 10
#define MAX_TIME_TO_REST 3

struct Library;

pthread_t tid[2];
int counter;
pthread_mutex_t lock;
struct Library lib;

struct Library
{
    unsigned int readers;
};

bool writersArbiter()
{
    pthread_mutex_lock(&lock);
    if (lib.readers == 0)
    {
        pthread_mutex_unlock(&lock);
        return true;
    }
    else
    {
        pthread_mutex_unlock(&lock);
        return false;
    }


    /*while(1)
    {
        if (pthread_mutex_trylock(&lock) == 0)
        {
            if (lib.readers == 0 && lib.writer == false)
            {
                pthread_mutex_unlock(&lock);
                pthread_create(&writersId, NULL, &writerInLib, NULL);
                return;
            }
        }
        else
            pthread_mutex_unlock(&lock);

        //sleep(losowa ilosc czasu);
    }*/
}

void *readerInLib()
{
    while (1)
    {
        unsigned int timeInLib = rand() % MAX_TIME_IN_LIB + 1;
        unsigned int timeToRest = rand() % MAX_TIME_TO_REST + 1;

        pthread_mutex_lock(&lock);

        lib.readers++;

        pthread_mutex_unlock(&lock);

        sleep(timeInLib);

        pthread_mutex_lock(&lock);

        lib.readers--;

        pthread_mutex_unlock(&lock);

        sleep(timeToRest);
    }
}

void *writerInLib()
{
    while(1)
    {
        if(writersArbiter() == true)
        {
            unsigned int timeInLib = rand() % MAX_TIME_IN_LIB + 1;
            unsigned int timeToRest = rand() % MAX_TIME_TO_REST + 1;

            pthread_mutex_lock(&lock);

            lib.writer = true;
            sleep(timeInLib);
            lib.writer = false;

            pthread_mutex_unlock(&lock);

            sleep(timeToRest);
        }
        else
        {
            sleep(rand() % 3 + 1);
        }
    }
}

int main(void)
{
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}