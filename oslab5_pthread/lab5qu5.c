#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



//mutex variable
pthread_mutex_t mutex;


void* routine(){

	pthread_mutex_lock(&mutex);

	//do stuff 
	pthread_mutex_unlock(&mutex);


}

int main(){
	pthread_t p1;

	//creating the mutex before creating the pthread ...
	pthread_mutex_init(&mutex,NULL);
	if(pthread_create(&p1,NULL,&routine,NULL)!=0){
		return 1;
	}



	pthread_mutex_destroy(&mutex);

	return 0;
}