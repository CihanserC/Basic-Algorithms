// THE COLLATZ CONJECTURE

#include<stdio.h>

int main()
{
	int n;
	int sum=0;
	
	
	printf("enter a number..:\n\n");
	scanf("%d",&n);
	
	while(n>1)
	{
		if(n%2==0) // if num is even
		{
			n = n/2 ;
			
			printf(" %d ->",n);
			
			if(n==1)
			{
				break;
			}
			
			sum = sum +1 ;
		}
		
		if(n%2==1) // if num is odd
		{
			n = 3*n +1 ;
			
			printf(" %d ->",n);
			
			if(n==1)
			{
				break;
			}
			sum = sum +1 ;
		}
	
	}
	printf("\n\n\n you have exit the program and it has reached to 1 !");
	printf("\n\n you have reached to 1 at %d steps.",sum);
	return 0;
}



