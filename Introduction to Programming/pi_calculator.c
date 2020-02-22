#include <stdio.h>

int main()
{      
	int i;
	double p = 0;

for ( i = 1; i <= 100; i++){
    if ( i % 2 == 0) 
	{
        p = p - (4.0 / (2 * i - 1));
    }
	else
	{
		p = p + (4.0 / (2 * i - 1));
	}
    
  }
	printf( "%f\t", p );
	return 0;
	
	
}