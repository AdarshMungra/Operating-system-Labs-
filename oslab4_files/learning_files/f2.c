#include <unistd.h>
#include <stdio.h>



int main(){
	
 	char buff[50];
 	int  n ,o;
 	n= read(0,buff,40);    // reading  from the termmial(user input) and storing it to the buffer variable 
 	sleep(3);
	o =write(1,buff,30);    //writing the buffer 


	printf("enter your whatever: %d\n your whatever is : %d\n",n,o);
	return 0;
}