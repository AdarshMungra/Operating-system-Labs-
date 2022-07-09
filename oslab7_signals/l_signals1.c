#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 
#include <string.h>

void sig_handler(){
	printf("inside the handler function");
}

int main(){

	//this can be used to get a signal to another process 
	//kill(pid ,sig)

	//child terminated  SIGCHLD 

	//signals to stop and start a certain process 
	//SIGSTP  (control+z)  or SIGSTOP
	//SIGCONT

	//user defined function 


	//sigaction()

	signal(SIGALRM,sig_handler);
	alarm(10);
	pause();


	return 0;
}