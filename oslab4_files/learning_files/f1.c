
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){

int fd;
char buffer[80];
char msg[50] ="hello world\n";

fd =open("check.txt",O_RDWR);  //assumming that the file is already been created    //also the file descriptor
printf("fd =%d",fd);
if(fd !=-1)  //if something goes wrong it will return -1   
{
	printf("\n check.txt opened with read write access\n");
	write(fd,msg,sizeof(msg));
	lseek(fd,0,SEEK_SET);
	read(fd,buffer,sizeof(msg));
	printf("\n %s was written to my file\n",buffer);
	close(fd);
}

return 0;


}