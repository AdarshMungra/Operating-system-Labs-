#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>




void fromParent(int x){
	printf("parent\n");

}

void fromChild(){
	printf("child1\n");

	//increment counter
}

void fromChild2(){
	printf("child2\n");
	//increment counter 
}



int main(){
	int p;
	int cp;
	int C1=0;
	int C2 =0;

	p=fork();
	if (p==0){
		//firstchild
		printf("in first child");

		cp =fork();
		if(cp ==0){
			//second child 
			printf("in second child");
		}
		signal(SIGUSR1,fromParent);
		pause();
		kill(getppid(),SIGUSR2);
	}
	else{
		//parent 


		for (int i = 0; i < 12; ++i)
		{
			if(i<6){
			sleep(10);
			kill();//for child1
			kill();//for child2
			pause();
			}
			else{
			sleep(10);
			kill();//for child1
			kill();//for child2
			pause();
			}
			
		}
		// printf("in Parent")
		// sleep(1);
		// kill(p,SIGUSR1);
		// signal(SIGUSR2,fromChild);
		// pause();


	}
	return 0;
}