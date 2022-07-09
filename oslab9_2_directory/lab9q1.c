
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <threads.h>
#include <fcntl.h>
#include <string.h>

void main(int argc, char const *argv[])
{
	char name[255];

	printf("Enter the name of the directory:");
	scanf("%s",&name);
	
	
	//char name[255]="mydir2";
	int val= mkdir(name,0777);

	if (val==0)
		printf("directory has been sucessfully created");
	else
		printf("Error in creation ");

}