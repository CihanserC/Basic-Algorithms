#include <stdio.h>

// Number digit finder

int main()
{
	int num = 654321;     
	int count=0;
	
	while(num!=0){
		printf("num = %d\n",num);
		num=num/10;
		count=count+1;
	}
	printf("Number has %d digits \n",count);
}
