#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#define FIFO_FILE "MYFIFO1"
#define FIFO_FILE2 "MYFIFO2"
#define MAX_BUF 1024

void main()
{
    char buf[MAX_BUF];
    int fd1, fd2;
    char un[15] = "mani";
    while (1)
    {
        char buf2[MAX_BUF];
        fd2 = open(FIFO_FILE, O_RDONLY);
        read(fd2, buf2, MAX_BUF);
        strcspn(buf2, '\n');
        if (strcmp(buf2, "stop") == 0)
        {
            break;
        }
        else
        {
            printf("Other user: %s\n", buf2);
        }
        close(fd2);
        fd1 = open(FIFO_FILE2, O_WRONLY);
        printf("%s :", un);
        fgets(buf, MAX_BUF, stdin);
        strcspn(buf, '\n');
        write(fd1, buf, strlen(buf));
        close(fd1);
        if (strcmp(buf, "stop") == 0)
        {
            break;
        }
        else
        {
        }
    }
}