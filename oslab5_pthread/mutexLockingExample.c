#include <stdio.h>
#include <pthread.h>

int I=0;

void * start(void*ptr);
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;
void main(){



int i;
int tid;
pthread_create(&tid,NULL,start,NULL);

for(i=0;i<10;i++){

	int k=I;
	pthread_mutex_lock(&mylock);
	I=I+1;
	sleep(1);

	/*
	printf("old value of I in parent is %d  New value is %d\n",k,I);
	printf("Parent -> Student's Name %d ------%d",i,I);
	scanf("%s",name[i]);
	ids[i]=i;
	*/
}

//sleep(2);
}

void *start(void *ptr){
	int j;
	for(j=0;j<10;j++){
		int i=I;
		//printf("old Value of I in parent is %d",i);

		pthread_mutex_lock(&mylock);
		I=I+i;
		printf(" --------------old value of I in child is %d New value is %d\n",i,I);
		//sleep(1);
	}
}