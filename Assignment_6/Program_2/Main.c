/*
	Problem statement : Write a program which create hole of size 1kb at the end of file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	char hole[1024] = {'\0'};
	
	iFd = open(argv[1],O_WRONLY|O_APPEND);
	if(iFd==-1)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	lseek(iFd,0,SEEK_SET);
	
	write(iFd,hole,sizeof(hole));
	
	return 0;
}
