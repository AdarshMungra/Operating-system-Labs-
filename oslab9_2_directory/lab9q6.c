#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	//recusive ls 
	DIR* dir =opendir(argv[1]);
	if(dir ==NULL){
		printf("unable to open directory:");
		return 0;

	}
	else{
		printf("\ndirectory is opened\n");
	}

	struct dirent* entity;
	entity = readdir(dir);
	while(entity!=NULL){
		if(entity->d_type==8){
			printf("%s\n",entity->d_name);
		}
		entity = readdir(dir);
		
	}

	printf("closing directory\n");
	closedir(dir);
	return 0;
}