#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int a[1000];
    int fd1[2];
    int fd2[2];
    int fd3[2];
    int fd4[2];
    int fd5[2];
    int fd6[2];
    int fd7[2];
    int fd8[2];
    int fd9[2];
    int fd10[2];
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    pipe(fd5);
    pipe(fd6);
    pipe(fd7);
    pipe(fd8);
    pipe(fd9);
    pipe(fd10);
    int status;
    int s;
    
    for(int i=0;i<1000;i++)
    {
        a[i]=i+1;
    }
    int pid=fork();
    if(pid==0)
    {
        close(fd1[0]);
        for(int j=0;j<100;j++)
        {
            s=s+a[j] ;
        }
        write(fd1[1],&s,sizeof(s));
        close(fd1[1]);
        
    }
    else
    {
        pid=fork();
        if(pid==0)
        {
             close(fd2[0]);
            for(int j=100;j<200;j++){
                 s=s+a[j] ;
            }
             write(fd2[1],&s,sizeof(s));
             close(fd2[1]);
        }
        else
        {
            pid=fork();
            if(pid==0)
            {   
                 close(fd3[0]);
                for(int j=200;j<300;j++){
                    s = s+a[j];
                }
                 write(fd3[1],&s,sizeof(s));
                 close(fd3[1]);
            }
            else
            {
                pid=fork();
                close(fd4[0]);
                if(pid==0)
                {   
                    for(int j=300;j<400;j++){
                        s = s+a[j];
                    }
                    write(fd4[1],&s,sizeof(s));
                    close(fd4[1]);
                }
                else
                    {
                        pid=fork();
                        if (pid == 0){
                            close(fd5[0]);
                             for(int j=400;j<500;j++){
                             s = s+a[j];
                        }
                         write(fd5[1],&s,sizeof(s));
                         close(fd5[1]);
                        }
                        else{
                            if(pid == 0){
                                close(fd6[0]);
                                 int s;
                                 for(int j=500;j<600;j++)
                                {
                                	 s = s+a[j];
                                 }  
                                  write(fd6[1],&s,sizeof(s));
                                  close(fd6[1]);
                            }
                            else{
                                pid = fork();
                                if(pid == 0){
                                     close(fd7[0]);
                                     for(int j=600;j<700;j++){
            							 s=s+a[j];
                                    }
                                     write(fd7[1],&s,sizeof(s));
                                    close(fd7[1]);
                                }
                                else{
                                     if(pid==0)
                                     {
                                         close(fd8[0]);
                                         for(int j=700;j<800;j++)
                                         {
            								s = s+a[j];
                                         }
                                          write(fd8[1],&s,sizeof(s));
                                        close(fd8[1]);
                                     }
                                     else{
                                          if(pid==0)
                                          {
                                               close(fd9[0]);
                                              for(int j=800;j<900;j++)
                                              {
            									s = s+a[j];
                                            }
                                             write(fd9[1],&s,sizeof(s));
                                             close(fd9[1]);
                                          }
                                          else{
                                               if(pid==0)
                                                {
                                                   close(fd10[0]);
                                                for(int j=900;j<1000;j++)
                                                  {
            											s = s+a[j];
                                                  }
                                                   write(fd10[1],&s,sizeof(s));
                                                   close(fd10[1]);
                                                }
                                                
    wait(&status);                                          
    wait(&status);
    wait(&status);
    wait(&status);
    wait(&status);
    wait(&status);
    wait(&status);
	wait(&status);
	wait(&status);
	wait(&status);
	int t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	read(fd1[0],&t1,sizeof(t1));
	read(fd2[0],&t2,sizeof(t2));
	read(fd3[0],&t3,sizeof(t3));
	read(fd4[0],&t4,sizeof(t4));
	read(fd5[0],&t5,sizeof(t5));
	read(fd6[0],&t6,sizeof(t6));
	read(fd7[0],&t7,sizeof(t7));
	read(fd8[0],&t8,sizeof(t8));
	read(fd9[0],&t9,sizeof(t9));
	read(fd10[0],&t10,sizeof(t10));
	int sum =t1+t2+t3+t4+t5+t6+t7+t8+t9+t10;
	printf("sum is",sum);
	close(fd1[0]);
	close(fd2[0]);
	close(fd3[0]);
	close(fd4[0]);
	close(fd5[0]);
	close(fd6[0]);
	close(fd7[0]);
	close(fd8[0]);
	close(fd9[0]);
	close(fd10[0]);
	
                                            }
                                        }
                                    }
                                    
                                }
                            }
                        }
                    }
    
        
                }
    
    
}
    
    
    return 0;
}
