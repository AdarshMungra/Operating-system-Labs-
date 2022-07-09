#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <sys/time.h>

void funct2(){
	printf("hello\n");
}

int main(){


 
  struct timeval start, end;
  gettimeofday(&start, NULL);
 


	for(int i=0;i<10;i++)
	{
		signal(SIGALRM,funct2);
		alarm(10);
		pause();
	}

gettimeofday(&end, NULL);
//printf("Time taken  is : %ld micro seconds\n",((end.tv_sec * 1000000 + end.tv_usec) -(start.tv_sec * 1000000 + start.tv_usec)));
//printf("Time taken  is : %ld seconds and  micro seconds\n",((end.tv_sec -start.tv_sec),(end.tv_usec-start.tv_usec)));



	return 0;

}