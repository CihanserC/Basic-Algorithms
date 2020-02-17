#include <stdio.h>
#include <stdlib.h>

// Sum of 2 matrices.

int main(){
	int a[3][3],b[3][3],c[3][3];
	int i,j;	
	printf("Fill the matrix A\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter A(%d,%d)\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}	
	printf("Fill the matrix B\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter B(%d,%d)\n",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	// ADD
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	// PRINT
	printf("Result is \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}		
	return 0;	
}

