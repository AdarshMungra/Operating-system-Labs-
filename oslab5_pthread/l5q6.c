#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


static pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;
static int fd;

void *sinPOUMW(void *args)
{
	double *value = args;
	for(int i = 0l ;i< 4; i++)
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
		memcpy(arr,&total,sizeof(total));
		printf("%lf\n",total);
		printf("%s\n",arr );
		write(fd,arr,4);
		value++;
		pthread_mutex_unlock(&mylock);
		sleep(1);
	}
}

void *cosPOUMW(void *args)
{
	double *value = args;
	for(int i = 0l; i< 4; i++)
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
		char buff[] = "\n";
		char arr[sizeof(total)];
		memcpy(arr,&total,sizeof(total));
		printf("%s\n",arr );
		write(fd,arr,4);
		write(fd,buff,2);
		value++;
		pthread_mutex_unlock(&mylock);
		sleep(1);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t p1;
	pthread_t p2;
	double x[] = {1.2,2.3,1};
	fd = open("angle.txt", O_RDWR| O_APPEND);
	pthread_create(&p1,NULL,sinPOUMW, (void *) x);
	pthread_create(&p2,NULL,cosPOUMW, (void *) x);
	close(fd);
	sleep(5);
	return 0;
}