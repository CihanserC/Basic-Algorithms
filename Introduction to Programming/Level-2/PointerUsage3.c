#include <stdio.h>
#include <stdlib.h>

// Pointer usage-2


void sum(int sumf)
{
   int x=5;
   int y=10;
   sumf=sumf+x+y;
   printf("value of the sumf=%d\n", sumf);
}

int main()
{
   int sum=100;
   printf("returned from function--sum=%d\n\n",sum(sum));
   system("PAUSE");
   return 0;    
}
