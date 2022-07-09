#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 

int main(){


	int fd[2], n;
	char buffer[100];
	pid_t p;
	pipe(fd);
	p=fork();
	//parent sends and child receives
	if(p>0){
		printf("Passing value to child\n");
		write(fd[1],"hello\n",6);
	}
	else
	{
		printf("child received data\n");
		n=read(fd[0],buffer,100);
		write(1,buffer,n);
	}


	//return 0;
}