/*
    Probem Statement : Write a program which accept file name and read first 5 characters from it.
*/

#include<stdio.h>                                   //for IO operations
#include<fcntl.h>                                   //for open and O_RDONLY macro
#include<string.h>                                  //for strcmp
#include<unistd.h>                                  //close fuction

int main(
    int argc,                                       //count of commandline arguments
    char *argv[]                                    //array of commandline arguments
    )
{
    int iFd = 0;
    char cBuffer[1];
    int iCnt = 0;
    int iNumRead = 0;

    if(argc!=2)                                     //if running executable only i.e ./Read
    {
        printf("Error : Inavalid number of arguments,\nUse %s <-h> or %s <-H> for help\n",argv[0],argv[0]);
        return -1;
    }
    if((strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"-H")==0))      //for ./Read -h or ./Read -H
    {
        printf("Use : %s <filename>\n",argv[0]);
        return 0;
    }
    else                                            //for ./Read filename
    {
        iFd = open(argv[1],O_RDONLY);               //to open file in read mode only

        if(iFd==-1)                                 //if file dosn't open
        {
            printf("Error : Unable to open %s\n",argv[1]);
            return -1;
        }
        else                                        //if file open successfully
        {
            for(iCnt=1;iCnt<=5;iCnt++)
            {
                iNumRead = read(iFd,cBuffer,1);     //to read 1 byte data from the file 
                if(iNumRead==0)                    //for end of file
                {
                    break;
                }
                else                                //for file having data
                {
                    printf("%c",cBuffer[0]);
                }
            }
            if(iCnt<5)                              //if the file has less than 5 characters
            {
                if(iCnt==1)                         //if the file is empty
                {
                    printf("Error : file is empty\n");
                    return -1;
                }
                printf("\nfile contains only %d characters\n",iCnt-1);
                return -1;
            }
            else
            {
                close(iFd);                     //closing file i.e releasing the resources
            }
            printf("\n");
        }
    }
    return 0;
}