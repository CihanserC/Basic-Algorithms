//selection sort

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num,a[100];
	int i,j,k,z;
	int min,tmp;
	
	
	printf("kac sayi girmek istersiniz ?\n");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		printf("enter %d. number!\n",i+1);
		scanf("%d",&a[i]);
	}
	
	
	
	//selection sort part --------------------
	
	for(i=0 ; i<num-1 ; i++)
	{
		min=i;
		
		for(k=i ; k<num ; k++)
		{
			if(a[k] < a[min])
			{
				min=k;
			}
		}
		
		tmp=a[i];
		a[i]=a[min];
		a[min]=tmp;
		
	
		
	}
	
	
	printf("SORTED LIST !!!\n\n");
	
	for(z=0;z<num;z++)
	{
		printf("%d.- %d \n  ",z+1,a[z]);
	}	
	
	
		
	
	
	
	
}
