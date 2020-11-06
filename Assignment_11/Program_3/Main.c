/*
	Problem Statement : Write a program which creates one child process , child process write something in
						unamed pipe and parent process read the data from that pipe.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	char Cmsg[1024] = {'\0'};
	char Pmsg[1024] = {'\0'};
	int iRet = 0;
	int iFd[2] = {0,0};
	//iFd[0] : reading;
	//iFd[1] : writing
	
	pipe(iFd);
	if((iRet = fork())==0)
	{
		close(iFd[0]);
		printf("Enter messege for parent..\n");
		scanf(" %[^'\n']",Cmsg);
		write(iFd[1],Cmsg,strlen(Cmsg));
		close(iFd[1]);
	}
	else
	{
		wait(&iRet);
		close(iFd[1]);
		read(iFd[0],Pmsg,sizeof(Pmsg));
		printf("Messege from child : %s\n",Pmsg);
		close(iFd[0]);
	}
	
	return 0;
}
