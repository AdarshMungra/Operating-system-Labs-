#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <pthread.h> 

int main(){

	//must include <unistd.h>
	//creating a new pipe
	//int pipe(int fd[2]);
	//fd[0] means read
	//fd[1] means write 
	int fd[2];
	int arr[] = {1,2,3,4,5,3,4,4};
	int arrSize = sizeof(arr) /sizeof(int);
	int start ,end;

	if(pipe(fd)==-1){
		return 1;
	}

	int id = fork();

	if(id ==-1){
		return 2;
	}

	//if in child
	if(id ==0){
		start =0;
		end = arrSize/2;
	}else{ //in parent 
		start = arrSize/2;
		end = arrSize;
	}

	//calculating the sum 
	int sum =0 ;
	int i;
	for(i =start;i<end;i++){
		sum += arr[i];
	}
	printf("the partial sum is %d\n",sum);

	if(id ==0){
		close(fd[0]);

		if(write(fd[1],&sum,sizeof(sum)) == -1){
			return 3;
		}
		close(fd[1]);
	}else{
		int sumFromChild;
		close(fd[1]);
		if(read(fd[0],&sumFromChild,sizeof(sumFromChild)) ==-1){
			return 4;
		}
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf(" the total sum is %d\n",totalSum);
		//wait(NULL);
	}




	return 0;
}