#include<stdio.h>
#include<stdlib.h>

void rectangle(){
	
	int i,j;
	
	for(i=1 ; i<10 ; i++){
		for(j=1 ; j<20 ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void triangle1(){
	
	int i,j;
	
	for(i=0 ; i<=10 ; i++){
		for(j=0 ; j<=i ; j++){
			printf("*");
		}
		printf("\n");
	}
}


int main()
{
	rectangle();
	triangle1();
	return 0;
}
