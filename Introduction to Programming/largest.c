#include <stdio.h>
#include <stdlib.h>

// Dynamic largest num finder.

int main()
{
    int i,n,n2,j,k;
    int *data;
    printf("Enter total number of elements ");
    scanf("%d",&n);   
    data=(int*)malloc(n*sizeof(int));  
    if(data==NULL)
    {
        printf("Error!!! memory not allocated.");
    }
    
    printf("********************* \n");
    for(i=0;i<n;i++)  /* Stores number entered by user. */
    {
       printf("Enter Number %d: ",i+1);
       scanf("%d",data+i);
    }
    int max=*(data);    //define max integer
    for(i=0;i<n-1;i++)  /* Loop to store largest number at address data */
    {
       if(max<*(data+i+1))/* Change < to > if you want to find smallest number */
     { 
          max=*(data+i+1);
           //*data=*(data+k);
       }
    }
    //printf("Largest element = %d",*data);
     printf("Largest element = %d",max);
    
  //  free(data);
  
  
  printf("\nEnter new size of array: ");
    scanf("%d",&n2);
    data = realloc(data,n2);
    
    for(j=n; j<n2; j++)
  {
     printf("Enter Number %d: ",j+1);
       scanf("%d",data+j);
    }
    
   // free(data);
    
    printf("okay\n");
    
    max=*(data);    
    for(i=0;i<n2-1;i++)  /* Loop to store largest number at address data */
    {
       if(max<*(data+i+1))/* Change < to > if you want to find smallest number */
     { 
          max=*(data+i+1);
           
       }
    }

     printf("Largest element = %d",max);
    
    getch();
    system("pause");
    return 0;
}
