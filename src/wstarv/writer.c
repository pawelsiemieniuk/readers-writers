#include "../var.h"


void* writer(int* id){
    int thread_id = *id;
    unsigned int writinig_time;
    time_t d_time;

    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.readers && !lib.writers && !que.readers){
            que.writers--;
            lib.writers++;
            printStatus(thread_id);

            d_time = time(NULL) - threads_last_entry[thread_id];
            if(threads_max_wait_time[thread_id] < d_time){
                threads_max_wait_time[thread_id] = d_time;
            }
            threads_last_entry[thread_id] = time(NULL);

            pthread_mutex_unlock(&lock);

            writinig_time = rand() % MAX_TIME + 1;
            sleep(writinig_time);

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