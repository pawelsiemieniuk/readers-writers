#include "../var.h"

// id nie bedzie potrzebne o ile nie bedziemy chcieli 
// zrobic dokladniejszej analizy czy na pewno wszyscy wchodza do biblioteki
void* reader(int* id){
    int thread_id = *id;
    unsigned int time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.writers){
            readers_queue--;
            lib.readers++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);
            
            time = rand() % MAX_TIME + 1;
            sleep(time);
            
            pthread_mutex_lock(&lock);
            lib.readers--;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);

            // Jesli damy czas odpoczynku po wyjsciu z biblioteki na 0
            // to na pewno pisarze beda glodni
            sleep(REST_TIME); 

            pthread_mutex_lock(&lock);
            readers_queue++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
    }
    
}