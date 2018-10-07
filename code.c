
#include <stdio.h>

#include <unistd.h>

int main()
{
    int array[1000],pid,sum=0,sum1=0,start=0,end=100,status;
    int n = 10 ;//number of processes
     for (int i = 0;i < 1000;i++){
        array[i] = i+1;
    }
    for(int i = 0;i < 10;i++){
        pid = fork;
        if(pid == 0){
            for(int i = start;i<end;i++){
                sum = sum+array[i];
            }
            start = start+100;
            end = end+100;
        }
       if(pid>0){
            wait(&status);
            printf("sum is %d",sum);
       }
    }

    return 0;
}

