/*
    Problem Statement : Write a program which accept name from command line argument and display it on
                        screen.
*/

#include<stdio.h>                                   //for IO operations
#include<string.h>                                  //for strcmp

int main(
        int argc,                                   //count of commandline arguments
        char *argv[]                                //array of commandline arguments
        )
{
    int iCnt = 0;
    if(argc==1)                                     //if there is only running executable i.e ./a.out or ./Myexe
    {
        printf("Error : Invalid number of arguments,\nUse %s <-h> or %s <-h> for help\n",argv[0],argv[0]);
        return -1;
    }
    else if((strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"-H")==0) && argc==2)  //for ./a.out -h or ./a.out -H or ./Myexe -h or ./Myexe -H
    {
        printf("Use : %s <first_name> <middle_name> <surname>\n",argv[0]);
        return 0;
    }
    else if(argc==2)                                //for ./a.out firstname or ./Myexe firstname
    {
        printf("Error : Invalid number of arguments,\nUse %s <-h> or %s <-h> for help\n",argv[0],argv[0]);
        return -1;
    }
    else if(argc==3)                                //for ./a.out firstname middlename  or ./Myexe firstname middlename
    {
        printf("Error : Invalid number of arguments,\nUse %s <-h> or %s <-h> for help\n",argv[0],argv[0]);
        return -1;
    }
    else if(argc==4) 
    {
        //for ./a.out firstname middlename lastname  or ./Myexe firstname middlename lastname
        if(((*argv[1]>='a') && (*argv[1]<='z')) && ((*argv[2]>='a') && (*argv[2]<'z')) && ((*argv[3]>='a') && (*argv[3]<='z')) ||
          ((*argv[1]>='A') && (*argv[1]<='Z')) && ((*argv[2]>='A') && (*argv[2]<'Z')) && ((*argv[3]>='A') && (*argv[3]<='Z'))
          )
        {  
            for(iCnt=1;iCnt<argc;iCnt++)
            {
                printf("%s ",argv[iCnt]);
            }
            printf("\n");
            return 0;
        }
        else                 //for having 4 command line arguments but other than firstname middlename and lastname 
        {
            printf("Error : Invalid arguments,\nUse %s <-h> or %s <-h> for help\n",argv[0],argv[0]);
            return -1;
        }
    }
    else
    {
        printf("Error : Invalid number of arguments,\nUse %s <-h> or %s <-h> for help\n",argv[0],argv[0]);
        return -1;
    }
}
