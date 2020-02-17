#include<stdio.h>

// Fibonacci numbers

int main()
{
	int i=0;
	int x=1;
	int oldx=0;
	int fib=1;
	int n;
	
	printf("enter how many fibbonacci elements do you want ? \n");
	scanf("%d",&n);
	printf("Results=\n\n");
	for(i=0 ; i<n ; i++)
	{
		fib = x + oldx ;
		oldx = x ;
		x = fib ;
		printf("%d \n",fib);
	}
}
