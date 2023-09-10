#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>

#define FIFO_FILE1 "/temp1/myfifo1"

#define FIFO_FILE2 "/temp1/myfifo2"

#define MAX_BUF 1024

//first _Pragma

int main()
{
    int fd1,fd2;
    char buf[MAX_BUF];
    char username[100];
    
    printf("enter username1:");
    fgets(username,sizeof(username),stdin);
    username[strcspn(username,"\n")]=0;
    
    //create fifos
    mkfifo(FIFO_FILE1,0777);
    mkfifo(FIFO_FILE2,0777);
    
    
    while(1)
    {
        fd1=open(FIFO_FILE1,O_WRONLY,0777);
        printf("%s:",username);
        fgets(buf,MAX_BUF,stdin);
        buf[strcspn(buf,"\n")]=0;
        write(fd1,buf,strlen(buf)+1);
        close(fd1);
        
        if(strcmp(buf,"stop")==0)
        {
            printf("stopped from user1");
            break;
        }
        
        //read from user2 with str2, then adding str2 to fd2;
        char str2[100];
        fd2=open(FIFO_FILE2,O_RDONLY,0777);
        read(fd2,str2,100);
        if(strcmp(str2,"stop")==0)
        {
            printf("stopped");
            break;
        }
        printf("other user:%s",str2);
        close(fd2);
        
        
    }
    
    
}



