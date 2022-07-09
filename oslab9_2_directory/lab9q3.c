#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(){
	//rewriting the first verion of ls ( called ls l )
	//list contents of the current directory 

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

		printf("%s\n",entry->d_name);
	}
	closedir(folder);
	printf("\nclosing the directory\n");

	return 0;
	




}