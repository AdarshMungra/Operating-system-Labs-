#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void *printId(void *args);

void *printName(void *args);

int main()
{
	pthread_t threadId_1;
	pthread_t threadId_2;

	int id[2], x = 1, y = 1;
	char *name[2] = {"john", "duck"};
	for(int i = 0; i< 2; i++)
	{
		id[i] = i;
		/*printf("enter student name: ");
		scanf("%s",&name[i]);*/
	}

	pthread_create(&threadId_2,NULL,printId, (void *) id);
	pthread_create(&threadId_1,NULL,printName,(void *) name);
	sleep(5);
	printf("exit parent");
	return 0;
}

void *printId(void *args)
{
	int *id = args;
	for(int j = 0; j< 2; j++)
	{
		printf("ID: %d\t", *id);
		if(j <1){
			id++;
		}
		sleep(1);
	}
}

void *printName(void *args)
{
	char **data = args;
	for (int i = 0;i<2;i++)
	{
		printf(" %s\n", *data);
		if(i <1){
			data++;
		}
		sleep(1);
	}
}