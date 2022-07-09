

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 
#include <string.h>


void *funct1(void *arg);

int main(){
	pthread_t threadid;
	int i,j;
	int x=1;

	pthread_create(&threadid,NULL ,funct1,(void *)&x);
	for(j=0;j<10;j++)
	{
		for(i=0;i<1000;i++);
			printf("Hi I'm the parent\n");
			sleep(2);
	}
	return 0;
}

void *funct1(void *arg){
	int i,j;
	for(j=0;j<10;j++){
		for (i=0; i<1000; i++);
		printf("Hi I'm the created thread\n");
		sleep(1);
	}
}