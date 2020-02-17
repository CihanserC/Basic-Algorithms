#include<stdio.h>

// Basic Calculator

int sum=0;
void toplama(int q,int w)
{
	
	scanf("%d %d",&q,&w);
	sum=q+w;

	printf("sonuc: %d",sum);
	
}

void cikarma(int e, int r)
{
	
	scanf("%d %d",&e,&r);
	sum=e-r;
	printf("sonuc:%d",sum);
}

void carpma(int t, int y)
{
	int sum=0;
	scanf("%d %d",&t,&y);
	sum=t*y;
	printf("sonuc:%d",sum);
}
void bolme(float j,float k)
{
	float sum=0;
	scanf("%f %f",&j,&k);
	sum=j/k;
	printf("sonuc:%f",sum);
}

int main()
{
	int x,y;
	int a;
	printf("hesap makinesi\n1-toplama\n2-cikarma\n3-carpma\n4-bolme");
	printf("\ndeger giriniz:");
	
	scanf("%d",&a);
	

	switch(a){
		
		case 1:{
				printf("toplama yapmak istedi?iniz sayilari giriniz:");
				toplama(x,y);
				break;
		} 
		
		
		case 2:{
			printf("cikarma yapmak istedi?iniz sayilari giriniz:");
			cikarma(x,y);
			break;	
		}
		
		
		case 3:{
			printf("carpma yapmak istedginiz sayilari secin:");
			carpma(x,y);
			break;
		}
		
		case 4:{
			
			printf("bolme yapmak istediginiz sayilari giriniz:");
			bolme(x,y);
				break;
			}
			default:{
				printf("1-2-3-4 sayilarindan ba?ka bir deger girdiniz!");
				
				break;
				
			}
			
	}
	
	
}
