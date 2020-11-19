#include "Header.h"

void SignalHandler(int iNo)
{
    printf("Signal received is : %d\n",iNo);
}
int main(int argc,char *argv[])
{
    int iRet = 0;
    int i = 0;
    if((iRet=fork())==0)
    {
        execl("./Sender","",NULL);
    }
    else
    {
        wait(&iRet);
        for(i=0;i<=64;i++)
            signal(i,SignalHandler);
        pause();
    }
    return 0;
}