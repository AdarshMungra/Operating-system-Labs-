#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void *sinPOUMW(void *args)
{
	double *value = args;
	double facto = 1;
	double total = *value;
	double pow = *value;
	int j = 1;
	for(int i = 2; i<=101; i++)
	{
		facto = facto * (j+1) *(j+2);
		j+=2;
		pow = pow * *value * *value;
		if(i %2 == 0)
		{
			total-=(pow)/(facto);
		}
		else
		{
			total+=(pow)/(facto);
		}
	}
	printf("%lf\n",total);
}

void *cosPOUMW(void *args)
{
	double *value = args;
	double facto = 1;
	double total = 1;
	double pow = 1;
	int j = 0;
	for(int i = 1; i<=100; i++)
	{
		facto = facto * (j+1) *(j+2);
		j+=2;
		pow = pow * *value * *value;
		if(i %2 == 1)
		{
			total-=(pow)/(facto);
		}
		else
		{
			total+=(pow)/(facto);
		}
	}
	printf("%lf\n",total);
}

int main(int argc, char const *argv[])
{
	pthread_t p1;
	pthread_t p2;
	double x = 1.5;
	pthread_create(&p1,NULL,sinPOUMW, (void *) &x);
	pthread_create(&p2,NULL,cosPOUMW, (void *) &x);
	sleep(5);
	return 0;
}