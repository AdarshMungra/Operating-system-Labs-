#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){

	int id = fork();
	printf("%d\n",getpid());
	return 0;


	
}