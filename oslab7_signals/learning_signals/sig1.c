#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//handler function 

void  handler(){
	printf("signal handler called\n");

}


int main(){

	signal(SIGALRM,handler);
	while(1){
		printf("%d",getpid());
		alarm(2);
		sleep(1);
	}
	pause();
	
	
	return 0;
}