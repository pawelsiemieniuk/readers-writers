#include "src/var.h"
#include "src/wstarv/reader.h"
#include "src/wstarv/writer.h"

int main(){
    int i = 0;
    int err;
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 3)
    {
        err = pthread_create(&(thr_id[i]), NULL, reader, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }
    
    while(i < 5)
    {
        err = pthread_create(&(thr_id[i]), NULL, writer, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    lib.readers = 0;
    lib.writers = 0;
    
    Library last_lib_state;
    last_lib_state.readers = 0;
    last_lib_state.writers = 0;

    while(1){
        //printf("R:%d , W: %d\n", lib.readers, lib.writer ? 1 : 0);
        //fflush(stdout);

        if(lib.readers != last_lib_state.readers || lib.writers != last_lib_state.writers){
            printf("- R:%d , W: %d\n", lib.readers, lib.writers ? 1 : 0);
            fflush(stdout);
            last_lib_state.readers = lib.readers;
            last_lib_state.writers = lib.writers;
        }
    }

    pthread_join(thr_id[0], NULL);
    pthread_join(thr_id[1], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}