/*
	Problem Statement : Write a program which is used to demonstrate concept of I/O redirection.
*/

#include<stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int iAns = 0;
	
	scanf("%d",&a);
	scanf("%d",&b);
	
	iAns = a + b;
	
	printf("The sum of %d and %d : %d\n",a,b,iAns);
	return 0;
}
