#include "../var.h"

// id nie bedzie potrzebne o ile nie bedziemy chcieli 
// zrobic dokladniejszej analizy czy na pewno wszyscy wchodza do biblioteki
void* writer(int* id){
    int thread_id = *id;
    unsigned int time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.readers && !lib.writers){
            writers_queue--;
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
            writers_queue++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
        
    }
}