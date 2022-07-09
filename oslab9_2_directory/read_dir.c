#include<stdio.h>
#include<dirent.h>


void main(){
	DIR * dp=opendir("./Dir1");

	if (dp==NULL){
		printf("Failure");
	}
	else{
		printf("Opening Successful");

		struct dirent *entries=readdir(dp);

		while (entries!=NULL){
			printf("\n%s \n", entries->d_name);
			entries=readdir(dp);

		}
	}
}//main