#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main()
{

	int fd, n;
	char buff[20];
	fd = open("test2.txt",O_WRONLY);
	n=read(fd,buff,10);
	open("target.txt",O_)
	write(1,buff,10);




	return 0;
}