// Dice frequency
#include <stdio.h>
#include <stdlib.h>
#define DICE 20
#define NO 7

int main(void) 
{
  int i,j;
  int frequency[NO]={0};
  int values[DICE]={1,1,3,4,4,4,5,6,5,6,5,2,2,2,5,5,5,5,4,2};

  for (i=0; i<DICE; i++){
  	frequency[values[i]]++;
  }
 
   	printf("#Number#\t #Frequency#\n");

  for (j=1;j<NO;j++){
  	printf("%3d\t\t%6d\n",j,frequency[j]);

  }
  printf("\n");
  system ("pause");
  return 0;
}

ß