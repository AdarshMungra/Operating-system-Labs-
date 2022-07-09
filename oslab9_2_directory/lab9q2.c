#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <dirent.h>


struct dirent {
	ino_t d_ino; 					/* inode number */
	off_t d_off; 					/* offset to the next dirent */
	unsigned short int d_reclen; 	/* length of this record */
	unsigned char d_type; 			/* type of file */
	char d_name[256]; 				/* filename */
};


int main(){
	//rewriting ls 

	//opendir()
	//readdir()
	//closedir()   close the directory after uses 
	//readdir()

	


	return 0;
}