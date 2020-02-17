#include<stdlib.h>
#include<stdio.h>

// LOOPS

int main(){
	
	int i,j,m,n;
	printf("enter m");
	scanf("%d",&m);
	printf("enter n");
	scanf("%d",&n);
	printf("Using For loops\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d_",j-i);
		}
		printf("*\n");
	}
	printf("Using While loops\n");
	while(i<m){
		j=0;
		while(j<n){
			printf("%d_",j-i);
			j++;
		}
		printf("*\n");
		i++;
	}
	printf("Do while Part \n");
	i=-10;
	do{
		j=0;
		do{
			printf("%d_",j-i);
			j++;
		}while(j<n);
		printf("*\n");
		i++;
	}while(i<m);
	system("Pause");
	return 0;
}
