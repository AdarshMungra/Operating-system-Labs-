#include <stdio.h>
#include <unistd.h>
#include<signal.h>


void funct1(){
printf("signal handler called\nalarm triggered\n");    //this signal handler function will execute automatically after 10 second 
}

int main(){
signal(SIGALRM,funct1);
alarm(10);
pause();
}