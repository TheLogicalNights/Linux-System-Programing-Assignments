/*
	Problem Statement : Write a program which is used to create unnamed pipe. Parent process creates new child
						process and both the processess will communicate with each other.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
	int iRet = 0;
	int iFd[2] = {0,0};
	char Pmsg[1024] = {'\0'};
	char Cmsg[1024] = {'\0'};
	
	pipe(iFd);
	
	if((iRet = fork())==0)
	{
		sleep(1);
		close(iFd[1]);
		read(iFd[0],Cmsg,1024);
		printf("Message from Parent : %s\n",Cmsg);
	}
	else
	{
		close(iFd[0]);
		printf("Enter messege for child : \n");
		scanf(" %[^'\n']s",Pmsg);
		write(iFd[1],Pmsg,strlen(Pmsg));
		wait(&iRet);
	}
	
	return 0;
}
