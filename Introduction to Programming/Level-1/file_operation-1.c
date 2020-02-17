#include<stdio.h>

int main()
{
	FILE *file;
	char ch;
	
	file=fopen("killer.txt","r");
	
	if((file=fopen("killer.txt","r"))!=NULL)
	{
		ch=fgetc(file);
		
		while(ch!=EOF)
		{
			printf("%c",ch);
			ch=fgetc(file);
			
		}
		
	}else{
		
		printf("File does not exist !");
		
	}
	
	fclose(file);
}
