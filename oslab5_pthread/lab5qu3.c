#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include <math.h>

//the functions using maclaurin series 
 void* sin_func(){
 	printf("testing the treads ");
 }

 void* cos_func(){
 	printf("testing the treads ");
 }



int main(){

	float degree ,rad;

	printf("enter angle in degrees\n");
	scanf("%f",&degree);
	//rad = degree * (M_PI /180.0);
	rad = degree * (3.14 /180.0);
	

	pthread_t th1;
	pthread_create(&th1,NULL,&sin_func,NULL);
	pthread_join(th1,NULL);
	

	return 0;
}