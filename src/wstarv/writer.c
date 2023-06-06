#include "../var.h"

void* writer(){
    unsigned int time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.readers && !lib.writers){
            //printf("Writer IN R: %d, W: %d\n", lib.readers, lib.writer ? 1 : 0);
            //fflush(stdout);
            lib.writers++;
            pthread_mutex_unlock(&lock);

            time = rand() % MAX_TIME + 1;
            sleep(time);

            pthread_mutex_lock(&lock);
            //printf("Writer OUT R: %d, W: %d\n", lib.readers, lib.writer ? 1 : 0);
            //fflush(stdout);
            lib.writers--;
            pthread_mutex_unlock(&lock);

            sleep(REST_TIME);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
        
    }
}