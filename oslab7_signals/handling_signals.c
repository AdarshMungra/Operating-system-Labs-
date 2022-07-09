#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int x= 0;

//the handler function
void handle_sigusr1(int sig){

	if(x  == 0){
		printf("HINT :remember that mulitplication is repetitive addition\n");
	}
	
}

int main(){

	int x;
	printf("Input number: ");
	scanf("%d",&x);
	printf("result %d *5 = %d\n",x,x*5);
	

	//sending signals among process

	//creating the 2 process 
	int pid;
	pid = fork();
	if(pid ==-1){
		return 1;
	}

	if(pid ==0){
		//child process
		sleep(5);
		kill(getppid(),SIGUSR1);

	}else{
		// in parent process

		//defining handler 
		struct sigaction sa ={0};
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1 ,&sa,NULL);


		int x;
		printf("what is the result of 3 x 5: ");
		scanf("%d",&x);
		if(x==15){
			printf("right!");
		}else{
			printf("wrong!");
		}
		wait(NULL);
	}

	return 0;

}