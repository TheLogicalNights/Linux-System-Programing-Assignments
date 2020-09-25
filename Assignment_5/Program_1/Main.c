/*
	Problem Statement : Write a program which writes structure in file. Structure should contains information of
			    Employee.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

struct Employee
{
	char name[80];
	int id;
	char project[80];
	float salary;
	char gender[10];
};

int main(int argc,char *argv[])
{
	char Newline[1] = {'\n'};
	char data[1024] = {'\0'};
	
	int iFd = 0;
	int iLen = 0;
	int iWrite = 0;
	int iCnt = 0;
	int iNo = 0;
	struct Employee emp;
	
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	iFd = open(argv[1],O_WRONLY|O_APPEND);
	if(iFd==-1)
	{
		printf("Error : Unable to open file\n");
		return -1;
	}
	else
	{
		printf("How many employees you want ?\n");
		scanf("%d",&iNo);
		for(iCnt=1;iCnt<=iNo;iCnt++)
		{
			printf("Enter employee name\n");
			scanf(" %[^'\n']s",emp.name);
			printf("Enter employee id\n");
			scanf(" %d",&emp.id);
			printf("Enter project name\n");
			scanf(" %[^'\n']s",emp.project);
			printf("Enter employee salary\n");
			scanf(" %f",&emp.salary);
			printf("Gender\n");
			scanf(" %s",emp.gender);
		
			sprintf(data,"Employee Id :-%d",emp.id);
			iLen = 	strlen(data);
			iWrite = write(iFd,data,iLen);
			iWrite = write(iFd,Newline,1);
			memset(data,'\0',sizeof(data));
		
			sprintf(data,"Employee Name :-%s",emp.name);
			iLen = 	strlen(data);
			iWrite = write(iFd,data,iLen);
			iWrite = write(iFd,Newline,1);
			memset(data,'\0',sizeof(data));
		
			sprintf(data,"Employee Project :-%s",emp.project);
			iLen = 	strlen(data);
			iWrite = write(iFd,data,iLen);
			iWrite = write(iFd,Newline,1);
			memset(data,'\0',sizeof(data));
		
			sprintf(data,"Employee Gender :-%s",emp.gender);
			iLen = 	strlen(data);
			iWrite = write(iFd,data,iLen);
			iWrite = write(iFd,Newline,1);		
			memset(data,'\0',sizeof(data));
		
			sprintf(data,"Employee Salary :-%f",emp.salary);
			iLen = 	strlen(data);
			iWrite = write(iFd,data,iLen);
			iWrite = write(iFd,Newline,1);
			iWrite = write(iFd,Newline,1);
			iWrite = write(iFd,Newline,1);
			memset(data,'\0',sizeof(data));
		}		
	}
	close(iFd);
	return 0;
}
