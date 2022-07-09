#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t parent, child;
    child = fork();
    for(int i = 0; i < 5; i++)
    {
        if(child == 0)
        {
            printf("i m the children with pid:%d\n", getpid());
            sleep(10);
        }
        else
        {
            printf("i m the parent with pid:%d\n", getpid());
            sleep(10);
        }
    }
    return 0;
}