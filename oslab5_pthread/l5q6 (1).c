#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

static int fd = 0;
int temp = 0;
static pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;


void *sinPOUMW(void *args)
{
	double *value = args;
	for(int k = 0;k< 3; k++)
	{
		pthread_mutex_lock(&mylock);
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
		char arr[sizeof(total)];
		printf("%f\n",total );
		snprintf(arr, sizeof(total), "%f", total);
		int x = write(fd,arr,4);
		char buff[] = "\t";
		write(fd,buff,2);
		value++;
		temp++;
		pthread_mutex_unlock(&mylock);
		sleep(1);
	}
}

void *cosPOUMW(void *args)
{
	double *value = args;
	for(int k = 0; k< 3; k++)
	{
		pthread_mutex_lock(&mylock);
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
		printf("%f\n",total );
		char buff[] = "\n";
		char arr[sizeof(total)];
		snprintf(arr, sizeof(total), "%f", total);
		int x = write(fd,arr,4);
		write(fd,buff,2);
		value++;
		temp++;
		if(temp == 6)
		{
			close(fd);
		}
		pthread_mutex_unlock(&mylock);
		sleep(1);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t p1;
	pthread_t p2;
	double x[] = {1.2,2.3,1};
	int fdtemp;
	fdtemp = open("angle.txt", O_WRONLY|O_CREAT,S_IRWXU);
	fd = fdtemp;
	pthread_create(&p1,NULL,sinPOUMW, (void *) x);
	sleep(1);
	pthread_create(&p2,NULL,cosPOUMW, (void *) x);
	sleep(5);
	return 0;
}