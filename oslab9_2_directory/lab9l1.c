#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <dirent.h>

int main(){

	//opening the directory and reading each entries 
	DIR *folder;
	struct dirent *entry;
	int files =0;


	folder = opendir(".");
	if(folder == NULL)
	{
		printf("unable to open directory");
		return 1;
	}
	else{
		printf("directory is opened:");
	}
	while( (entry = readdir(folder))){
		files++;
		printf("File %3d :  %s\n" ,files,entry->d_name);
	}

	closedir(folder);

	return 0;


}