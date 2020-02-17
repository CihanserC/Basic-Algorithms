#include <stdio.h>

// (n*(n+1))/2;

int main()
{
	int counter=0 ;
	int sum=0;
	int n;
	printf("Enter n");
	scanf("%d",&n);
	while(counter<n){
		counter = counter + 1;
		sum = sum + counter;
	}
	printf("%d",sum);
}
