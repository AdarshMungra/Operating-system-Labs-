#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 
#include <string.h>

void fromParent(int x){
	printf("Hi! - received signal from parent\n");
}

void fromChild(){
	printf("Hi!-Received signal from child\n");
}


int main(){

	//int p;
	pid_t p;

	p=fork();

	if(p==-1){
		return 1;
	}
	if(p==0){
		signal(SIGUSR1 ,fromParent);
		pause();
		kill(getppid(),SIGUSR2);
	}
	else{
		sleep(1);
		kill(p,SIGUSR1);
		signal(SIGUSR2,fromChild);
		pause();
	}

	return 0;
}