#include <stdio.h>

// Number Guessing program try1

main()
{
int score;
printf("Enter a value between 0 or 20 for score=");
scanf("%d",&score);
if (0<score && score<=20)
  printf("almost right!\n");
else printf("Sorry, it's wrong\n");
system("pause"); 
return 0;
}