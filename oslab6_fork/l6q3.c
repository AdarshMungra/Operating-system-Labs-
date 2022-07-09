#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t parent, child;
    int num[] = {12,3,43,22,45};
    child = fork();
    for(int i = 0; i < 5; i++)
    {
        if(child == 0)
        {
            if(i % 2 == 1)
            {
                num[i] = num[i] * 2;
                printf("i m the children with pid:%d, the modified number %d is at an odd place, %d\n", getpid(), num[i],i);
                sleep(1);
            }
            else
            {
                printf("i m the children with pid:%d, the number %d is at place, %d\n", getpid(), num[i],i);
            }
        }
        else
        {    
            printf("i m the parent with pid:%d, the number %d is at place, %d\n", getpid(), num[i],i);
            sleep(1);   
        }
    }
    return 0;
}