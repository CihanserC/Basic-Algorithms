#include <stdio.h>

// Takes average of 3 numbers.
main()
{

  float num1;
  float num2;
  float num3;
   
  printf("num1:");
  scanf("%f",&num1);
  printf("\nnum2:");
  scanf("%f",&num2);
  printf("\nnum2:");
  scanf("%f",&num3);

printf("Average=%.2f\n\n",(num1+num2+num3)/3);

system("pause"); 
return 0;
}