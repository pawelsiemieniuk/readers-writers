#include "src/var.h"
#include "src/wstarv/wstarv.h"
#include "src/rstarv/rstarv.h"
#include "src/exclude/exclude.h"



int main(int argc, char** argv){

    que.readers = readers_num = atoi(argv[1]);
    que.writers = writers_num = atoi(argv[2]);

    pthread_t readers_thr_id[readers_num];
    pthread_t writers_thr_id[writers_num];

    srand(time(NULL));

    printStatus(-1); // Wypisanie poczatkowego stanu

    for(int i = 0; i < readers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i;

        pthread_create(&(readers_thr_id[i]), NULL, reader, id);
    }

    for(int i = 0; i < writers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i + 1 + readers_num;
        
        pthread_create(&(writers_thr_id[i]), NULL, writer, id);
    }

    pthread_mutex_lock(&lock);
    //pthread_cond_signal(&writers_lock);
    pthread_cond_broadcast(&readers_lock);
    pthread_mutex_unlock(&lock);

    for(int i = 0; i < readers_num; i++){
        pthread_join(readers_thr_id[i], NULL);
    }
    for(int i = 0; i < writers_num; i++){
        pthread_join(writers_thr_id[i], NULL);
    }

    return 0;
}