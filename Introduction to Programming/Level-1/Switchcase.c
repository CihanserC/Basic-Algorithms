#include<stdlib.h>
#include<stdio.h>
int main(){
	
// If-else & Switch case usage.
	int a;
	printf("Enter a number");
	scanf(" %d",&a);
	/* 
	// You can use if-else instead of switch case.
	if(a==1){
		printf("first\n");
	}else if(a==2){
		printf("second\n");
	}else{
		printf("default\n");
	}
	*/
	switch(a){
		case 1:
			printf("first\n");
			break;
		case 2:
			printf("second\n");
			break;
		default:
			printf("default\n");
			break;
	}
	
	system("Pause");
	return 0;
}
