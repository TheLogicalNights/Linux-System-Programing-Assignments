/*
	Problem Statement : Accept filename from user and open it
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	
	if(argc != 2)
	{
		printf("Error : Inavalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	if((strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"-H")==0) && argc==2)
	{
		printf("Use : make ARGS = \"filename\" run to execute\n");
		return 0;
	}
	else if(argc==2)
	{
		iFd = open(argv[1],O_RDONLY);
		
		if(iFd==-1)
		{
			printf("Error : Unable to open %s\n",argv[1]);
			return -1;
		}
		else
		{
			printf("%s opened successfully with File Descriptor : %d\n",argv[1],iFd);
		}
	}
	return 0;
}
