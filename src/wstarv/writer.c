#include "../var.h"


void* writer(int* id){
    int thread_id = *id;
    unsigned int writinig_time;

    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.readers && !lib.writers && !que.readers){
            {
                que.writers--;
                lib.writers++;
                printStatus();

                logEntryTime(thread_id);
            }
            pthread_mutex_unlock(&lock);

            writinig_time = rand() % MAX_TIME + 1;
            sleep(writinig_time);

            pthread_mutex_lock(&lock);
            {
                lib.writers--;
                printStatus();
            }
            pthread_mutex_unlock(&lock);

            sleep(REST_TIME);

            pthread_mutex_lock(&lock);
            {
                que.writers++;
                printStatus();
            }
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
        
    }
}