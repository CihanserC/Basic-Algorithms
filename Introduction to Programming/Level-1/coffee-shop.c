#include <stdio.h>

// Coffe shop simple order interface.

int main()
{
	char drinkC;
	int menuChoice,aroma,temprature;
	printf("*** Welcome to Coffee Shop *** \n");
	printf("Press t for Tea OR c for Coffee\n");
	scanf("%c",&drinkC);
	
	if(drinkC=='c')
	{
		printf("COFFEE MENU\n");
		printf("1. Macchiato \t 2. Cappuchino \t 3. Americano");
		scanf("%d",&menuChoice);
		if(menuChoice==1)
		{
			printf("Select Aroma\n");
			printf("1. Caramel 2. Vanilla");
			scanf("%d",&aroma);
			if(aroma==1)
			{
				printf("1.HOT OR 2.COLD?\n");
				scanf("%d",&temprature);
				if(temprature==1)
				{
					printf("your hot caramel macchiato is ready");
				} else 
				{
					printf("your cold caramel macchiato is ready");
				}
			} else 
			{
				printf("HOT OR COLD?");
			}
		} else if (menuChoice==2)
		{
			
		} else if(menuChoice==3)
		{
			
		} else 
		{
			
		}
		
	} else if(drinkC='t')
	{
		printf("TEA MENU \n");
		//TRY MORE LOGICAL MENU FOR TEA
		//YOU CAN ASK THE TEMPRATURE FIRST AND STORE GLOBALLY ETC.
	} else 
	{
		printf("Wrong choice-try again\n");
	}
	
}
