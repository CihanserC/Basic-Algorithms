#include <stdio.h>
#include <stdlib.h>

// Dynamic sum with pointers.

int main()
{
	int *array, toplam = 0,i,n ;
	
	printf("Please enter the quantity:");
	
	scanf("%d",&n);
	
	array=(int*)malloc(sizeof(int)*n);
	// n byte area allocated
	int *pointer;
	pointer = array;

	printf("Before array fill operation\n");
	printf ("pointer adr %d , value %d \n",pointer,*pointer);
	printf ("pointer adr+1 %d , value %d \n",pointer+1,*pointer+1);

	if(array==NULL)
	{
		printf("cant allocated");
	} else 
	{
		printf("allocated");
	}
	
	
	for(i=0;i<n;i++)
	{
		printf("enter number \n");
		scanf("%d",array+i);
		toplam = toplam + *(array+i);		
	}
	
	printf("sum = %d\n", toplam);
	

	printf("Before Free operation\n");
	printf ("pointer adr %d , value %d \n",pointer,*pointer);
	printf ("pointer adr+1 %d , value %d \n",pointer+1,*pointer+1);
	

	free(array);

	
	printf("After Free Operation\n");
	printf ("pointer adr %d , value %d \n",pointer,*pointer);
	printf ("pointer adr+1 %d , value %d \n",pointer+1,*pointer+1);

}
