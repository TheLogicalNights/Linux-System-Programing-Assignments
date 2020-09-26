/*
	Problem Statement : 	Write a aprogram which accept directory name and file name from user and create file in
				that directory.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	char path[80] = {'\0'};
	if(argc!=3)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	sprintf(path,"%s/%s",argv[1],argv[2]);
	creat(path,0777);
	return 0;
}
