#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char const *argv[])
{
	for(int i =0;i<argc;i++){
		printf("the argument count:%i  and the argument :%s\n",i ,argv[i]);
	}



	return 0;
}	