#include <stdio.h>
#include <unistd.h>
#include<signal.h>


//void( *signal(int,void (*)(int))(int);
// unsigned int alarm(unsigned int seconds)


//defining th sighandler function 
void sig_handler(int signum){
	printf("a signal was generated inside the handler function !");

}


int main(){

	signal(SIGALRM, sig_handler);//the signal handler 
	alarm(2);// calling the alarm funciton which will create a signal after 2 seconds 

	//for loop to show how many seconds have passed
	for(int i=1;;i++){
		printf("%d : inside the main function \n",i);
		sleep(1); //delay of one second after each iteration 
	}



	return 0;
}