#include<stdio.h>
#include<stdlib.h>

/*
int avg(int a,int b)
{
	int average;
	
	average =(a+b)/2 ;
	
	return average;
	

}

int main()
{
	int a,b;
	int c;
	
	printf("enter 1. number:\n");
	scanf("%d",&a);
	
	printf("enter 2. number:\n");
	scanf("%d",&b);
	
	c=avg(a,b);
	
	printf("average is %d",c);
}

*/
int* sum(int* pages[50],int* n);
{
	int allpagenum=0;
	for(i=0;i<n;i++)
	{
		allpagenum = allpagenum +pages[i];

		
		
	}
	
	return allpagenum;
	
}

int main()
{
	int n,i=0;
	int pages[50];
	int answer;
	
	printf("how many books do you have?\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("please write your %d. book page number:\n",i+1);
		scanf("%d",&pages[i]);
		
	}
	
	answer = sum(pages[50]);
	
	printf("your books total page number is : %d",answer);
	
}


