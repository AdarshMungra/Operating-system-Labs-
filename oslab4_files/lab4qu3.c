#include<sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>



int main(){

	struct timev start ,end;
	


	gettimeofday(&start,NULL);
	int p_id;
	p_id = getpid();
 	for( int i=0;i<10;i++){
 		sleep(2);
 		printf("the pid is :%d\n",p_id);
 	}
	gettimeofday(&end,NULL);
q
	printf("the second:%ld\n",(end.tv_sec-start.tv_sec));
	printf( "milli seconds:%ld\n",(end.tv_sec-start.tv_sec)/1000);
	printf("the microseconds:%ld\n",(end.tv_usec-start.tv_usec));

	printf("Program with pid %d has run for %ld milliseconds.",p_id,(end.tv_usec-start.tv_usec));

	return 0;
}


