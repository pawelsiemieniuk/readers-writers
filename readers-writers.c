#include "src/var.h"
#include "src/wstarv/reader.h"
#include "src/wstarv/writer.h"
#include "src/rstarv/reader.h"
#include "src/rstarv/writer.h"
#include "src/exclude/reader.h"
#include "src/exclude/writer.h"



int main(int argc, char** argv){
    int err;

    readers_num = atoi(argv[1]);
    writers_num = atoi(argv[2]);

    pthread_t readers_thr_id[readers_num];
    pthread_t writers_thr_id[writers_num];


    if (pthread_mutex_init(&lock, NULL) != 0){
        printf("\n mutex init failed\n");
        return -1;
    }


    for(int i = 0; i < readers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i;
        err = pthread_create(&(readers_thr_id[i]), NULL, reader, id);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
    }
    for(int i = 0; i < writers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i;
        err = pthread_create(&(writers_thr_id[i]), NULL, writer, id);
        if (err != 0)
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