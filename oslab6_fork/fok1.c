#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	pid_t q;
	printf("before fork\n");
	q=fork(); //calling fork 
	if(q<0){
		printf("error");
	}
	else if(q==0) //child process
	{
		printf("child having pid : %d\n",getpid());
		printf("the parent's pid : %d\n ", getppid());
	}
	else    //q>0  parent process
	{
		printf("Parent having pid %d\n",getpid());
		printf("my child's pid : %d\n",q);
	}

}