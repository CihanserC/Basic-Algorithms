#include<stdlib.h>
#include<stdio.h>

// Student grade system.

void printarray(float farray[100],int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("Student %d grade is %.2f\n",i+1,farray[i]);
	}
}
int main()
{
	int n,i=0;
	float grades[100],sum=0.0,avg;
	
	printf("Enter number of students\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Enter Grade\n");
		scanf("%f",&grades[i]);
		sum=sum+grades[i];
	}
	
	printarray(grades,n);
	avg=sum/n;
	printf("Average is %f\n",avg);
	return 0;	
}
