/*
	Problem Styatem : 	Write a program which accept directory name from user and delete all such files whose
				size is greater than 100 bytes.
*/

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *pDir = NULL;
	struct dirent *dirptr = NULL;
	struct stat fileptr;
	int iFd = 0;
	int iFlag = 0;
	
	char path[500] = {'\0'};
	
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	pDir = opendir(argv[1]);
	
	if(pDir==NULL)
	{
		printf("Error : Unable to open directory\n");
		return -1;
	}
	else
	{
		while((dirptr = readdir(pDir)) != NULL)
		{
			sprintf(path,"%s/%s",argv[1],dirptr->d_name);
			stat(path,&fileptr);
			if(S_ISREG(fileptr.st_mode))
			{	
				if(fileptr.st_size > 100)
				{
					printf("Removing : %s  %ld\n",dirptr->d_name,fileptr.st_size);
					remove(path);
					iFlag = 1;
				}
			}			
		}
		if(iFlag==0)
		{
			printf("There are no file having size more than 100 bytes\n");
		}
		else
		{
			printf("All files are removed having size more than 100 bytes\n");
		}
	}
	return 0;
}
