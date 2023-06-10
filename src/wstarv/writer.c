#include "../var.h"

// id tylko do pokazania ktore procesy gloduja
void* writer(int* id){
    int thread_id = *id;
    unsigned int writing_time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.readers && !lib.writers && !que.readers){
            que.writers--;
            lib.writers++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);

            writing_time = rand() % MAX_TIME + 1;
            sleep(writing_time);

            pthread_mutex_lock(&lock);
            lib.writers--;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);

            sleep(REST_TIME);

            pthread_mutex_lock(&lock);
            que.writers++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
        
    }
}