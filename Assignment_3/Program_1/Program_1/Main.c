/*
	Problem Statement : Write a program which accept directory name from user and print all file names from that
			    directory.
*/


#include<stdio.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
	DIR *fd;
	struct dirent *dirptr;
	if(argc>2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : Insufficient arguments please enter directory name\nUse <make help> for help");
		return -1;
	}
	else
	{
		fd = opendir(argv[1]);
		if(fd==NULL)
		{
			printf("Error : Unable to open directory\n");
			return -1;
		}
		else
		{
			printf("iNode no\t\tFilename\n");
			printf("---------------------------------------------\n");
			do
			{
				dirptr = readdir(fd);
				if(dirptr==NULL)
				{
					printf("Directory dosnt have more files.\n");
					return 0;
				}
				else
				{
					printf("%ld\t\t\t",dirptr->d_ino);
					printf("%s\n",dirptr->d_name);
				}
			}while(fd!=NULL);
		}
		closedir(fd);
	}
	return 0;
}
