#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char const *argv[])
{
	//stat 
	//d_name , d_type, d_reclen, d_off, d_ino 


	DIR  * folder;
	struct dirent *entry;
	

	folder = opendir("."); // the dot means the current directory 

	if(folder ==NULL)
	{
		printf("\nunable to open directory\n");
		return 1;
	}
	else{
		printf("\ndirectory is opened\n");
	}

	while((entry = readdir(folder))){

		printf("filename:%d\n",entry->d_type);
	}
	closedir(folder);
	printf("\nclosing the directory\n");

	return 0;
	

	return 0;
}