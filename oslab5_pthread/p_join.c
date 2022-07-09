#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 


void *computation();// this line is important 

//step2: the function 
void *computation(){
	printf("computation\n");
	return NULL;
}



int main(){

	//step1 : create the thread 
	pthread_t thread1;
	pthread_create(&thread1,NULL,computation,NULL);

	//step2: youe need a function that you want to run on the thread 

	//step3: use pthread_join to join back the thread of execution to the main 
	pthread_join(thread1,NULL);

	return 0;
}