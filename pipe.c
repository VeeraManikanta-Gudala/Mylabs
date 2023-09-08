#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
    int fd[2];
    pipe(fd);
    int pid = fork();
    if(pid == 0){
        close(fd[0]);
        char msg[100] = "Hello from child";
        write(fd[1],msg,100);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        char buff[100];
        read(fd[0],buff,100);
        printf("Message from child: %s\n",buff);
        close(fd[0]);
    }
}