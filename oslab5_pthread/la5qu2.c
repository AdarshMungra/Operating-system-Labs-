



#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 
#include <string.h>


void *routine(){
	char student[];
	int stuID[];
	for(int i=0 ;i<10;i++){
		print("enter your student name:");

	}
}

int main(){

	pthread_t thd1;
	pthread_t thd2;

	if(pthread_create(&thd1,NULL,routine,NULL)!=0){
		return 1;
	}
	if(pthread_create(&thd2,NULL,routine,NULL)!=0){
		return 2;
	}
	if(pthread_join(thd1,NULL)!=0){
		return 3;
	}
	if(pthread_join(thd2,NULL)!=0){
		return 4;
	}

	return 0;
}