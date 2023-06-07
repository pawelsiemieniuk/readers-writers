#include "../var.h"

// id nie bedzie potrzebne o ile nie bedziemy chcieli 
// zrobic dokladniejszej analizy czy na pewno wszyscy wchodza do biblioteki
void* reader(int* id){
    int thread_id = *id;
    unsigned int time;
    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.writers){
            lib.readers++;
            printf("ReaderQ: %d WriterQ: %d [in: R:%d W:%d] - IN READER     %d\n", 
                    readers_num - lib.readers, 
                    writers_num - lib.writers, 
                    lib.readers, lib.writers, thread_id);
            fflush(stdout);
            pthread_mutex_unlock(&lock);
            
            time = rand() % MAX_TIME + 1;
            sleep(time);
            
            pthread_mutex_lock(&lock);
            lib.readers--;
            printf("ReaderQ: %d WriterQ: %d [in: R:%d W:%d] - OUT READER    %d\n", 
                    readers_num - lib.readers, 
                    writers_num - lib.writers, 
                    lib.readers, lib.writers, thread_id);
            fflush(stdout);
            pthread_mutex_unlock(&lock);

            // Jesli damy czas odpoczynku po wyjsciu z biblioteki na 0
            // to na pewno pisarze beda glodni
            sleep(REST_TIME); 
        }
        else{
            pthread_mutex_unlock(&lock);
        }
    }
    
}