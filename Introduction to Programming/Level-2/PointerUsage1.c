#include <stdio.h>
#include <stdlib.h>

// Pointer usage-1

void toplama(int *sumf)
{
   int x=5;
   int y=10;
   *sumf+=x+y;
   printf("value of the sumf=%d\n", *sumf);
}

int main()
{
   int sum=100;
   toplama(&sum);
   printf("returned from function--sum = %d \n\n", sum);
   return 0;    
}
