#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){


	// the pipe() system call creates a new pipe
	// returns 0 on  success or -1 on error 
	int pipe(int filedes[2]);

	// follow by the fork()  to create the process os that they can share data 
	int p= fork();


	int fd =open("/home/adarsh/Documents/oslab/oslab8_pipes/pipes/test.txt",O_RDONLY);
	char buf[25];
	n = read(fd,buf,20);
	write(1,void *buf)
	close(fd);


	if(p ==0){
		//in child
		printf("hi , am child");

	}
	else(p== 1){
		//in parent 
		printf("hi, am parent ");
		

	}

	return 0;

}