#include "var.h"


void printStatus(){
    printf("ReaderQ: %2d WriterQ: %2d [in: R: %2d W: %2d]\n", 
            que.readers, que.writers, lib.readers, lib.writers);
    fflush(stdout);
}

void signalHandler(){
    time_t end_time = time(NULL);
    time_t process_time = end_time - start_time;
    char thr_type[7] = "READER";
    
    pthread_mutex_lock(&lock);

    printf("\n\nProcess time: %lds\n\n", process_time);
    printf("[ Id] |   Name | Longest time in queue | %% of longest time |\n");

    for(int i = 0; i < readers_num + writers_num; i++){
        if(i == readers_num){
            strcpy(thr_type, "WRITER");
        }
        time_t d_time = end_time - threads_last_entry[i];
        if(threads_max_wait_time[i] < d_time){
            threads_max_wait_time[i] = d_time;
        }

        float percentage = ((float)threads_max_wait_time[i] / (float)process_time) * (float)100;

        printf("[%3d] | %s | %20lds | %16.2f%% |\n", 
                i, thr_type, threads_max_wait_time[i], percentage);
    }
    exit(0);
} 

void logEntryTime(int id){

    time_t d_time = time(NULL) - threads_last_entry[id];

    if(threads_max_wait_time[id] < d_time)
        threads_max_wait_time[id] = d_time;

    threads_last_entry[id] = time(NULL);
}