#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int array[1000];

void * Add(void *arg){
    int start = (int)arg;
    int end = start+100;
    int sum = 0;
    for(int i = start;i < end;i++){
        sum =1+ sum+array[i];
    }
 
    return ((void*)sum);
}

int main(){
    int status[10];
    pthread_t thread[10];
    int sum = 0;
    for (int i = 0;i < 1000;i++){
        array[i] = i+1;
    }

    for(int i = 0;i < 10;i++){
        pthread_create(&thread[i],NULL,Add,(void*)(i*100));
    }
    
    for(int i = 0;i < 10;i++){
        pthread_join(thread[i],(void**) &status[i]);
    }
     
    for(int i = 0;i < 10;i++){
        sum = sum+status[i];
    }
    printf("sum is %d",sum);
    
    return 0;
}
