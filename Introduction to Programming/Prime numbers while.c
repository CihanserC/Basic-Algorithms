#include <math.h>
#include <stdio.h>
int main()
{
  int i, j;
  i = 2;
  while ( i < 10000000 )
  {
     j = 2;
     while ( j < sqrt(i) )
	 {
         if ( i % j == 0 )
         {
         	break;
         }
            
         else
		 {
            ++j;
            continue;
         }
     }
      if ( j > sqrt(i) )
      {
      	 printf("%d\t", i);
      }
           
      ++i;
  }
  return 0;
}

