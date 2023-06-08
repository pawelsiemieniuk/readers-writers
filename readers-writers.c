#include "src/var.h"
#include "src/wstarv/wstarv.h"
#include "src/rstarv/rstarv.h"
#include "src/exclude/exclude.h"



int main(int argc, char** argv){
    int err;

    que.readers = readers_num = atoi(argv[1]);
    que.writers = writers_num = atoi(argv[2]);

    pthread_t readers_thr_id[readers_num];
    pthread_t writers_thr_id[writers_num];


    if (pthread_mutex_init(&lock, NULL)){
        printf("\n mutex init failed\n");
        return -1;
    }

    printStatus(0); // Wypisanie poczatkowego stanu

    for(int i = 0; i < readers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i+1;
        err = pthread_create(&(readers_thr_id[i]), NULL, reader, id);

        if (err)
            printf("\ncan't create thread :[%s]", strerror(err));
    }

    for(int i = 0; i < writers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i + 1 + readers_num;
        err = pthread_create(&(writers_thr_id[i]), NULL, writer, id);
        
        if (err)
            printf("\ncan't create thread :[%s]", strerror(err));
    }


    for(int i = 0; i < readers_num; i++){
        pthread_join(readers_thr_id[i], NULL);
    }
    for(int i = 0; i < writers_num; i++){
        pthread_join(writers_thr_id[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}