#include <stdio.h>

// Switch Case usage.

main()
{

  int num;
  int a=5;
  int b=10;
  int c=15;
  int d=20;
  
  printf("enter a number:");
  scanf("%d",&num);

  switch (num)
  {
     case 5: printf("num=a\n\n");break;
     case 10: printf("num=b\n\n");break;
     case 15: printf("num=c\n\n");break;
     case 20: printf("num=d\n\n");break;
     default:printf("please input 5,10,15 or 20\n\n");break; 
  }  
     
system("pause"); 
return 0;
}