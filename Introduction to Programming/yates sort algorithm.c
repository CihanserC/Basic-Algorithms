#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void printArray (int arr[], int n)
{
	int i ;
    for (i = 0; i < n; i++)
    {
    	printf("%d.Index = %d\n",i,arr[i]);

    }
    printf("\n");
}
 
void randomize ( int arr[], int n )
{
	int i;
    
    srand ( time(NULL) );
 
   
    for (i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
 
        swap(&arr[i], &arr[j]);
    }
}
 
int main()
{	int c;
    int arr[256];
    
    for(c=0;c<256;c++)
    {
    	arr[c]=c;
    }
    
    int n = 256;
    randomize (arr, n);
    printArray(arr, n);
 
    return 0;
}
