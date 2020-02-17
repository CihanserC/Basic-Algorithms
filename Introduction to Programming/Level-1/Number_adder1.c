#include <stdio.h>

// Number adder.

int main()
{
	int a=0;
	int sum=0;
	while(a!=-1){
		printf("Current number is %d Enter -1 to exit\n",a);
		scanf("%d",&a);
		if(a!=-1)
		{
			sum=sum+a;	
		}
	}
	printf("Result is : %d",sum);
}
