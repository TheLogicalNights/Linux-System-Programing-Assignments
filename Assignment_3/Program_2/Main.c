#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	DIR *pDir;
	struct dirent *dirptr;
	struct stat fileptr;
	int iFd = 0;
	int iRet = 0;
	
	if(argc>2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : Insufficient arguments\nUse <make help> for help\n");
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
			printf("iNode number\tFilename\t\tType\n");
			printf("-------------------------------------------------------------\n");
			do
			{
				dirptr = readdir(pDir);
				if(dirptr==NULL)
				{
					printf("Directory dosn't have more files\n");
					break;
				}
				else
				{
					printf("%ld\t\t",dirptr->d_ino);
					printf("%s\t\t",dirptr->d_name);
					iFd = open(dirptr->d_name,O_RDONLY);
					if(iFd==-1)
					{
						printf("Error : Unable to open file\n");
						break;
					}
					else
					{
						iRet = fstat(iFd,&fileptr);
						switch(fileptr.st_mode & S_IFMT)
						{
							case S_IFREG : printf("Regular File\n"); break;
							case S_IFDIR : printf("Directory File\n"); break;
							case S_IFCHR : printf("Character Device\n"); break;
							case S_IFBLK : printf("Block Device\n"); break;
							case S_IFIFO : printf("FIFO or pipe\n"); break;
							case S_IFSOCK : printf("Socket\n"); break;
							case S_IFLNK : printf("Symbolic Link\n"); break;
						}
					}					
				}
			}while(pDir!=NULL);
		}
	}
	closedir(pDir);
	return 0;
}
