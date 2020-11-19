#include "Header.h"
int main(int argc,char *argv[])
{
    int iSignal = 0;

    printf("Enter signal to send...\n");
    scanf(" %d",&iSignal);

    kill(getppid(),iSignal);
}