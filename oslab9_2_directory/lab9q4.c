#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>


int main(int argc, char const *argv[])
{
	


	//rewriting the first verion of ls ( called ls l )
	//list contents of the current directory 
	//give a specified directory by the user using argc and argv 

	DIR  * folder;

	struct dirent *entry;

	
	


	//folder = opendir("."); // the dot means the current directory 

	folder = opendir(argv[1]);

	if(folder ==NULL)
	{
		printf("\nunable to open directory ,%s :\n" ,argv[1]);
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