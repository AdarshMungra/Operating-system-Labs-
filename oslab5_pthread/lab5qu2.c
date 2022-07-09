#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char * student_array[10] = {"tom", "sam" ,"sasuke" ,"sara", "tom","jerry","morty","beth","rick","summer"};
int student_id[10] ={1,2,3,4,5,6,7,8,9,10};


//the display function 
void* display_student_array_function(){
	printf("testing thread \n");
	for(int i=0;i<10;i++)
	{
		printf("%s ", student_array[i]);
	}

}
void* display_student_id_array_function(){
	printf("testing thread \n");
	for(int i=0;i<10;i++)
	{
		printf("%i\n",student_id[i]);
	}
}

 int main()
{
	/*
	//print the array the normal way 
	for(int i=0;i<10;i++)
	{
		printf("N %s ", student_array[i]);
		printf("%i\n",student_id[i]);
	}
	*/

	//the thread variables
	pthread_t t1 ,t2;
	pthread_create(&t1, NULL, &display_student_array_function ,NULL);
	pthread_join(t1,NULL);
	pthread_create(&t2, NULL, &display_student_id_array_function ,NULL);
	pthread_join(t2,NULL);

	return 0;
}