#include<stdlib.h>
#include<stdio.h>

//Factorial calculator.

int main()
{
	int n,i;
	int result=1;
	
	printf("Enter the num : \n");
	scanf("%d",&n);
	
	if(n<0)
	{
		printf("Only positive numbers have factorial");
	
		printf("Error , Enter a number that greater than 0.");
	
	}else{
		
		for(i=1;i<=n;i++)
		{
			result=result*i;	
			//printf("%d!=%d\n",i,result);
		}
		
	printf("%d!=%d\n",n,result);
	}	
	system("Pause");
	return 0;	
}
