/*
	Problem Statement : Accept a filename and mode from user and check whether that file is accesible for that process in that perticular
			    mode or not.
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iRet = 0;
	int iMode = 0;
	
	if(argc>3)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	if(argc==2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	if(argc==1)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	if(((strcmp(argv[2],"read")==0) || ((strcmp(argv[2],"Read")==0))))
	{
		iMode = 1;
	}
	else if(((strcmp(argv[2],"write")==0) || ((strcmp(argv[2],"Write")==0))))
	{
		iMode = 2;
	}
	else if(((strcmp(argv[2],"execute")==0) || ((strcmp(argv[2],"Execute")==0))))
	{
		iMode = 3;
	}
	else
	{
		printf("Error : Invalid Mode\nUse <make help> for help\n");
		return -1;
	}
	
	iRet = access(argv[1],F_OK);
	
	if(iRet==0)
	{
		switch(iMode)
		{
			case 1 : iRet = access(argv[1],R_OK);
				 if(iRet==0)
				 {
				 	printf("File is accessible to read for process\n");
				 }
				 else
				 {
				 	printf("File is not accessible to read (Access denied !)\n");
				 }
				 break;
				 
			case 2 : iRet = access(argv[1],W_OK);
				 if(iRet==0)
				 {
				 	printf("File is accessible to write for process\n");
				 }
				 else
				 {
				 	printf("File is not accessible to write (Access denied !)\n");
				 }
				 break;
				 
			case 3 : iRet = access(argv[1],X_OK);
				 if(iRet==0)
				 {
				 	printf("File is accessible to execute for process\n");
				 }
				 else
				 {
				 	printf("File is not accessible to execute (Access denied !)\n");
				 }
				 break;
		}
	}
	else
	{
		printf("Error : %s dosn't exist\n",argv[1]);
		return -1;
	}
	close(iFd);
	return 0;
}
