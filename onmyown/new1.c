#include <stdio.h>
#include <stdlib.h>


int funct(){


	return ;
}


int main()
{

	pid_t parent1;
	printf("here\n");

	int x;
	x= getppid();
	printf("%d",x);

	int y;
	y= fork();

	int fdForPipe[2];
	pipe(fdForPipe);


	int *a;  // pointer to an int 
	char *c; // pointer to a char 




	if(y==0){
		//in child
		printf("\nin child\n");
	}
	else{
		//in parent 
		printf("\nin parent\n");
		sleep(1);
	}

	return 0;
}			