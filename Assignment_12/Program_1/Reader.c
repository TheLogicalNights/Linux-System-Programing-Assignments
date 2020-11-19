#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int iFd = 0;
	char msg[512];

	iFd = open("/tmp/myfifo",O_RDONLY);
    if(iFd==-1)
    {
        printf("Error : Unable to open pipe\n");
        return -1;
    }
	
	read(iFd,msg,sizeof(msg));
	printf("Messege from Process-1 is : %s\n",msg);
    
	close(iFd);

    return 0;
}
