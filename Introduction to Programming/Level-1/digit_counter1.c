#include<stdio.h>

int main()
{
	int count=0,a;
	
	printf("please enter a number :\n");
	scanf("%d",&a);
	
	while(a!=0)
	{
		a=a/10;
		
		count=count+1;
	}
	
	printf("your number has %d digits.",count);
	
	
	
}
