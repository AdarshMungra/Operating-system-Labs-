
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 


// the functions

void *funct1();
void *funct2();

void *funct1(){
	printf("do stuff");
}

void *funct2(){
	printf("do stuff");
}




int main(){

	pthread_t th1;
	pthread_t th2;

	pthread_create(&th1,NULL,funct1,NULL);
	pthread_create(&th2,NULL,funct2,NULL);



	return 0;
}