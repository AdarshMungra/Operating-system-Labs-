#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>



int main(){

	int fd;   // declare a file descriptor

	//to write to the screen use file descriptor 1
	int n;

	n =write(1,"hello\n",6);
	printf("value of n is %d\n",n);


	//read
	char b[30];
	read(0,b,10); //read from screen
	write(1,b,10);  //write to screen 
	printf("\nhere 1\n");

	int h;
	char j[30];
	h=read(0,j,10);
	write(1,j,h);
	printf("\nhere 2\n");


	//read and write to files using open system call

		//reading from a file and displaying it to the screen
	int n3;
	int fdread;
	char buf3[50];
	fdread = open("testing.txt",O_RDONLY|O_CREAT);
	n =read( fdread,buf3,sizeof(buf3));
	write(1,buf3,sizeof(buf3));
	printf("\nhere 3\n");

	//writing to another file 
	// but the target file doesnot exit yet
	int n4;
	int fd4;
	int fd5;
	char buf4[50];
	fd4 = open("testing.txt",O_RDONLY);
	n4 =read( fd4,buf4,sizeof(buf4));
	//fd5 =open("target.txt",O_CREAT|O_WRONLY|O_APPEND);
	fd5 =open("target.txt",O_CREAT|O_WRONLY);
	write(fd5,buf4,sizeof(buf4)); //writing to the target file 
	write(1,buf4,sizeof(buf4));
	printf("\nhere 4\n");

	//lseek 
	//read specific stuff within a file 
	// read particular location 
	//remember when reading a file you always from the first char..
	//lseek offset the start and end 


	int n6,fd6,f7,f8;
	char buf6[10];
	fd6 =open("seeking.txt",O_RDWR|O_CREAT);
	read(fd6,buf6,10);
	write(1,buf6,10);
	lseek(fd6,10,SEEK_CUR); 
	printf("\n\n");
	read(fd6,buf6,10);
	write(1,buf6,10);   //use SEEK_SET for read from ...

	f7=lseek(fd6,10,SEEK_SET);
	printf("\n\n");
	read(fd6,buf6,10);
	write(1,buf6,10);
	printf("\n\n");
	printf("\nhere 5\n");

	f8=lseek(fd6,-11,SEEK_END);
	printf("\n\n");
	read(fd6,buf6,10);
	write(1,buf6,10);

	printf("\nhere 6\n");

	





	// char buf[25];
	// fd =open("file1.dat",O_RDWR|O_CREAT,S_IRWXU);
	// if(fd ==-1){
	// 	printf("Error Number %d\n",errno);
	// 	//&n=read(fd,buf,sizeof(buf));
	// }
	// //write(1,n,20);





	return 0;
}