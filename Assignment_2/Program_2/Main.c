#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iMode = 0;
	if(argc>3)
	{
		printf("Error : Insufficient number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==2)
	{
		printf("Error : Insufficient number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : Insufficient number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	if((strcmp(argv[2],"Read")==0) || (strcmp(argv[2],"read")==0))
	{
		iMode = 1;
	}
	else if((strcmp(argv[2],"Write")==0) || (strcmp(argv[2],"write")==0))
	{
		iMode = 2;
	}
	else if((strcmp(argv[2],"Read-Write")==0) || (strcmp(argv[2],"read-write")==0))
	{
		iMode = 3;
	}
	else if((strcmp(argv[2],"Append")==0) || (strcmp(argv[2],"append")==0))
	{
		iMode = 4;
	}
	else
	{
		printf("Error : Invalid Mode\nUse <make help> for help\n");
		return -1;
	}
	switch(iMode)
	{
		case 1 : iFd = open(argv[1],O_RDONLY);
			 if(iFd==-1)
			 {
			 	printf("Error : Unable to open file in read mode\n");
			 }
			 else
			 {
			 	printf("File opened successfully in read mode with file descriptor : %d\n",iFd);
			 }
			 break;
			 
		case 2 : iFd = open(argv[1],O_WRONLY);
			 if(iFd==-1)
			 {
			 	printf("Error : Unable to open file in write mode\n");
			 }
			 else
			 {
			 	printf("File opened successfully in write mode with file descriptor : %d\n",iFd);
			 }
			 break;
		
		case 3 : iFd = open(argv[1],O_RDWR);
			 if(iFd==-1)
			 {
			 	printf("Error : Unable to open file in read-write mode\n");
			 }
			 else
			 {
			 	printf("File opened successfully in read-write mode with file descriptor : %d\n",iFd);
			 }
			 break;				 

		case 4 : iFd = open(argv[1],O_APPEND);
			 if(iFd==-1)
			 {
			 	printf("Error : Unable to open file in append mode\n");
			 }
			 else
			 {
			 	printf("File opened successfully in append mode with file descriptor : %d\n",iFd);
			 }
			 break;
	}
	return 0;
}
