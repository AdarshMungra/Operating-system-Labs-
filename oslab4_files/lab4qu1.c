#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>



int main(){

	//declare the variable names 
	int p_id;


	//assigning the variables to the functions
	p_id = getpid();
	//pid_t getppid(void);


	//printf("the process id is : %d\n the parent id is :%d\n", getpid(),getppid());
	printf("the other p id :%d ",p_id);
	sleep(2);

	return 0;
}