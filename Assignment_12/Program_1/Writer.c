/*
	Problem Statement : Write a program which creates two process as reader and writer and that processess
						should communicate with each other using FIFO.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int iFd = 0;
	char msg[512];
	
	mkfifo("/tmp/myfifo",0666);
	
	iFd = open("/tmp/myfifo",O_WRONLY);
	if(iFd==-1)
	{
		printf("Error : Unable to open pipe..\n");
		return -1;
	}

	printf("Enter msg for Process-2\n");
	scanf(" %[^'\n']s",msg);
	
	write(iFd,msg,strlen(msg));
	
	close(iFd);

	return 0;
}
