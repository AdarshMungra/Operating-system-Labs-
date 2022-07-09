#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(){

	// create the variables  

	int fd;
	//char buff[50];

	char *buff;
	buff = (char * )malloc(25);

	//assign file descriptor to the open function 

	fd =open("/home/adarsh/Documents/oslab5/oslab4/lab44.dat",O_RDONLY);

	// the while loop 
	while(read(fd,buff,25)>0){
		printf("%s",buff);
		free(buff);
	}
	close(fd);

	return 0;
}