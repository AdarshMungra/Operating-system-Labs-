
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>




//create orphan process ( child without parent ) parent terminate first 
int main(){

	pid_t p;
	p=fork();

	if(p==0){

		sleep(2); //making the child sleep and letting the parent terminate
		printf("i am child having PID %d\n",getpid());
		printf("my parent PID is %d\n",getppid());
	}
	else{
		printf("i am parent having PID %d\n",getpid());
		printf("My child is %d\n",p);
	}


	//create a zombie process 
	//when the parent does not of the child has finish 
	//parent still wait for its child to return
	//the child is the zombie because its entry will be still in the process because the parent clear them

	pid_t p2;
	p2=fork();

	if(p2==0){

		printf("i am child having PID %d\n",getpid());
		printf("my parent PID is %d\n",getppid());
	}
	else{
		//sleep(3);
		wait(NULL);
		printf("i am parent having PID %d\n",getpid());
		printf("My child is %d\n",p);
	}



	return 0;
}