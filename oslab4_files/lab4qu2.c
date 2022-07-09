#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

#include <math.h>


//gettimeofday function 


int power(int num, int expo)
{
	
	for(int i =0;i<expo-1;i++){
		num *=num;
	}
	return num;
}

int main(){

	//the struct is the 1st argument of the gettimeofday function 
	struct timeval start ,end;
	

	gettimeofday(&start,NULL);
	int  result = pow(3,4);
	printf( "the power is : %d\n",result);
	//sleep(2);
	gettimeofday(&end,NULL);

	printf("the second:%ld\n",(end.tv_sec-start.tv_sec));
	printf( "milli seconds:%ld\n",(end.tv_sec-start.tv_sec)/1000);
	printf("the microseconds:%ld\n",(end.tv_usec-start.tv_usec));

	return 0;
}