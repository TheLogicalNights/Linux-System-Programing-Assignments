/*
    Problem Statement : Write a program which creates child process and parent process will communicate with
                        child process by sending signals.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>

void SignalHandler(int iNo)
{
    printf("Signal Received : %d\n",iNo);
}
int main()
{
    int i = 0;
    int iRet = 0;
    if((iRet = fork())==0)
    {  
        kill(getppid(),SIGUSR1);
    }
    else
    {
        signal(i,SignalHandler);
        pause();
    }
    return 0;
}
