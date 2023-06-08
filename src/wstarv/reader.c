#include "../var.h"

// id tylko do pokazania ktore procesy gloduja
void* reader(int* id){
    int thread_id = *id;
    unsigned int time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.writers){
            que.readers--;
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
            que.readers++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
    }
    
}