#include <stdio.h>

// 1-2-3 BOM game

int main()
{
	int counter = 0;
	while(counter<20)
	{
		counter = counter + 1 ;
		if(counter%5!=0)
		{
			printf("%d \n",counter);
		} else 
		{
	    	printf("%d BOM \n",counter);
		}
		
	}
}
