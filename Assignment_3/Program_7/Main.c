/*
	Problem Statement : Write program which accept directory name from user and delete all empty files from that
			    directory.
*/

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	DIR *pDir;
	struct dirent *dirptr;
	struct stat fileptr;
	int iStat = 0;
	int iUnlink = 0;
	int iFlag = 0;
	char cPath[300];
	
	if(argc>2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
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
				
				sprintf(cPath,"%s/%s",argv[1],dirptr->d_name);
				iStat = stat(cPath,&fileptr);
				if(iStat==-1)
				{
					printf("Error : Something went wrong please try again\n");
					break;
				}
				else
				{
					if(fileptr.st_size==0)
					{
						iUnlink = unlink(cPath);
						if(iUnlink==-1)
						{
							printf("Error : Unable to remove %s\n",dirptr->d_name);
							break;
						}
						else
						{
							printf("%s -> removed\n",dirptr->d_name);
							iFlag++;
						}
					}
				}					
						
			}
			if(dirptr==NULL)
			{
				if(iFlag==0)
				{
					printf("There is no empty file in directory\n");
				}
				else
				{
					printf("All empty files are removed successfully\n");
				}
			}
		}
	}
	closedir(pDir);
	return 0;
}
