#include "../var.h"

// id tylko do pokazania ktore procesy gloduja
void* writer(int* id){
    int thread_id = *id;
    unsigned int writing_time;

    while(1){

        pthread_mutex_lock(&lock);
        pthread_cond_wait(&writers_lock, &lock);
        {
            que.writers--;
            lib.writers++;
            printStatus(thread_id);
        }
        pthread_mutex_unlock(&lock);

        writing_time = rand() % MAX_TIME + 1;
        sleep(writing_time);

        pthread_mutex_lock(&lock);
        {
            lib.writers--;
            printStatus(thread_id);

            writers_counter++;
            if(writers_counter < writers_num){
                pthread_cond_signal(&writers_lock);
            }
            else{
                writers_counter = 0;
                pthread_cond_broadcast(&readers_lock);
            }
        }
        pthread_mutex_unlock(&lock);

        sleep(REST_TIME);
        
        pthread_mutex_lock(&lock);
        {
            que.writers++;
            printStatus(thread_id);
        }
        pthread_mutex_unlock(&lock);
    }
}