#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

	//declare the variables
	int fd ;
	char buff[100];
	

	//the arrays 
	char student[5][20];
	char student_id[5][10];
	char dob[5][10];
	char gender[5][7];
	char marital status[5][10];


	//open a file using O_CREAT

	fd =open("/home/adarsh/Documents/oslab5/oslab4/lab45.dat",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);

	//checks 
	if(fd ==-1){
		errExit("open");
	}







	return 0;
}