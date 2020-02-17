#include <stdio.h>

// multiples of 6

int main()
{
	int num;
	int counter = 0;
	int sum=0;
	printf("Enter num \n");
	scanf("%d",&num);
	while(counter<num)
	{
		if(counter%2==0 && counter%3==0)
		{
			sum = sum + counter;
		}
		counter=counter+1;
	}
	printf("SUM = %d",sum);
}
