#include<stdlib.h>
#include<stdio.h>

// Array usage.

int main()
{
	int i;
	int array[5];
	array[0]=1;
	array[1]=2;
	array[2]=3;
	array[3]=4;
	array[4]=5;
	/*
	for(i=0;i<5,i++)
	{
		array[i]=i+1;
	}
	*/
	int iarray[5]={1,2,3,4,5};
	for(i=0;i<5;i++)
		printf("%d ",iarray[i]);
	printf("\n");
	
	float farray[5]={1.2, 2.4, 3.6};
	for(i=0;i<5;i++)
		printf("%.2f ",farray[i]);
	
	printf("\n");
	
	char carray[5]={'a','b','c','d','e'};
	for(i=0;i<5;i++)
	{
			printf("%c ",carray[i]);

	}
	return 0;
}
