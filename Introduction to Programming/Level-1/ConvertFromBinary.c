
//HOMEWORK 2

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void randbin()       //arrayin içine rastgele 0 ve 1 atan fonksiyon
{
	int i=0;
	int binarray[64];

	binarray[64]=rand()%2;
	
	for(i=0 ; i<64 ; i++)
	{
		printf("%d",rand()%2);

	}
}

int binary_decimal(int num)  // binary den decimal e ceviren fonksiyon.
{   
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    while (num > 0)
    {
        rem = num % 10;
        decimal_num = decimal_num + rem * base;
        num = num/ 10 ;
        base = base * 2;
    }
    return decimal_num;
}


	

int main()
{
	int a,b,c=0,d,e;
	srand(time(NULL));
	int i=0,select;
	int decimal_output;
	int binarray[16];	
	
	printf("\nRandom binary numbers with 64 elements : \n \n");
	randbin();
	printf("\n\n 1 for float : \n 2 for integer : \n 3 for character : \n");
	scanf("%d",&select);
	
	switch(select)
	{
		case 1 :
			{
					//    FLOAT ÝÇÝN FONKSÝYON YAZ!!!!
			
			
				break;
			}
			
		case 2 :
			{
				binary_decimal(binarray[16]);
				
				decimal_output = binary_decimal(binarray[16]);
				
				printf("Your random  1. integer number is : %d",decimal_output);
				
				a = binary_decimal(binarray[32]);
				b = binary_decimal(binarray[16]);
				c = a-b ; 
				
				printf("Your random 2. integer number is : %d",c);
				c=0;
				d = binary_decimal(binarray[48]);
				
				c = d-a;
				
				printf("Your random 3. integer number is : %d",c);
				
				c=0;
				e = binary_decimal(binarray[64]);
				
				c = e-d;
				
				printf("Your random 4. integer number is : %d",c);

				
				 
							

				

				
				
				
				
				//   	 ÝNTEGER ÝCÝN FONKSÝYON YAZ!!!! 
				
				break;
			}
			
			
		case 3 :
			{
				//      CHARACTER ÝCÝN FONSÝYON YAZ !!!!
					
				break;
			}
			
		default : printf("you have entered invalid value!"); break;
			
			
	}

	
}


