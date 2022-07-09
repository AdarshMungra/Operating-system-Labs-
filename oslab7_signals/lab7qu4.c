#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>

void fromParent(int x){
	printf("Hi!-Received signal from Parent\n");
}

void fromChild(){
	printf("Hi!-Received signal from Child\n");
}
int main(){
	int p;
	p=fork();
	if (p==0){
		signal(SIGUSR1,fromParent);
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