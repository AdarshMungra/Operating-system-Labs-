#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void * start_function(void * arg){
	//do stuff 
	printf("inside the function! bruh");
}

int main(){

	//thread variable buh 
	pthread_t thread1;

	//gotta create the thread bruh 
	pthread_create(&thread1,NULL,&start_function,NULL);

	pthread_join(thread1,void);

	return 0;
}