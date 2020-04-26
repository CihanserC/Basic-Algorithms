#include<stdlib.h>
#include<stdio.h>

// Exponentiate iterative and recursive functions

int power(int base, int exp){//c iterative
	int i;
	int result=1;
	for(i=0;i<exp;i++){
		
		result=result * base;
	}
	return result;
}
int powerRec(int base,int exp){//recursive
	if(exp==1){
		return base;
	}else{
		return powerRec(base,exp-1) * base;
	}
}
int factRec(int a){
	
	if(a == 0){
		return 1;
	}else{
		return a * factRec(a-1);
	}
	
}

int main(){
	int a,b;
	printf("Enter Base\n");
	scanf("%d",&a);
	printf("Enter Exp\n");
	scanf("%d",&b);
	int result=powerRec(a,b);
	printf("Result of %d power %d is %d\n",a,b,result);
	
	printf("Enter Factorial\n");
	scanf("%d",&a);	
	result =factRec(a);
	printf("Result of %d factorial  %d\n",a,result);
		
	system("Pause");
	return 0 ;
}
