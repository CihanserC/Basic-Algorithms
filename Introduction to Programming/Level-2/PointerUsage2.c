#include <stdio.h>

// Pointer usage

int main()
{
	int array[]={5,7,9,11,3,5};   

	int i; 
	
	int *ptr;  
	ptr = &array[0];  
	int *ptr2;
	ptr2 = &array[1];
	int *pointer;
	pointer = array;
	
	printf("1st element of array : %d  \n ", array[0]);
	printf("1st element of array : %d  \n ", *ptr);
	printf("1st element of array : %d \n", *pointer);
	printf("1st element of array : %d \n", *ptr2);

	

	printf("\n\n");

	printf("second element of array : %d \n",*(pointer+2));
	printf("second  element of array : %d  \n ", *(ptr2));

	printf("\n\n");
	
	for(i=0; i<6; i++) 
	{
		printf("arrays %d. element is %d and address is %p:\n",i+1,*(pointer+i),(pointer+i));
	}
	

	printf("4th element of array  = %d  array address : %d  pointer address : %p \n",array[3],&array[3],(ptr+3));

	
	return 0;
}
