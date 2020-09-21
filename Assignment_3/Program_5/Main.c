/*
	Problem Statement : Write a program which accept directory name and file name from user and check whether
			    that file is present in that directory or not.
*/


#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *pDir;
	struct dirent *dirptr;
	
	if(argc>3)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
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
	else
	{
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
				if((strcmp(dirptr->d_name,argv[2])==0))
				{
					break;
				}
			}				
		}
		if(dirptr==NULL)
		{
			printf("%s not fount in directory %s\n",argv[2],argv[1]);
			closedir(pDir);
			return 0;
		}		
		else
		{
			printf("%s is present in the directory\n",argv[2]);
			closedir(pDir);
			return 0;
		}	
	}
}


