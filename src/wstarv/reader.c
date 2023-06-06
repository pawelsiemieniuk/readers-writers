#include "../var.h"

void* reader(){
    unsigned int time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.writers){
            //printf("Reader IN-1 R: %d, W: %d\n", lib.readers, lib.writer ? 1 : 0);
            //fflush(stdout);
            lib.readers++;
            sleep(1);
            //printf("Reader IN-2 R: %d, W: %d\n", lib.readers, lib.writer ? 1 : 0);
            //fflush(stdout);
            pthread_mutex_unlock(&lock);
            
            time = rand() % MAX_TIME + 1;
            sleep(time/10);
            
            pthread_mutex_lock(&lock);
            //printf("Reader OUT R: %d, W: %d\n", lib.readers, lib.writer ? 1 : 0);
            //fflush(stdout);
            lib.readers--;
            pthread_mutex_unlock(&lock);

            sleep(REST_TIME);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
    }
    
}