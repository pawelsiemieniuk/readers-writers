#include "../var.h"

// id tylko do pokazania ktore procesy gloduja
void* writer(int* id){
    int thread_id = *id;
    unsigned int time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.readers && !lib.writers && !que.readers){
            que.writers--;
            lib.writers++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);

            time = rand() % MAX_TIME + 1;
            sleep(time);

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