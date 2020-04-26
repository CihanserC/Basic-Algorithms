#include <stdio.h>
#include <stdlib.h>
#define LEN 10

// File ops with C.

struct student
{
   char name [LEN];
   int g1;
   int g2;
}class[2];

int main(void)
{
int i;
int a,b;
FILE *inputfile=NULL;
FILE *outputfile=NULL; 

  int sum=0;
  float ave;
   
  for (i=0;i<2;i++){
    scanf ("%s %d %d",class[i].name,&(class[i].g1),&(class[i].g2));
    sum=sum+class[i].g1+class[i].g2;}
    
  ave=sum/4;
  
  printf ("\nGPA=%.2f",ave);
  
 outputfile = fopen( "test.txt", "w" );
  for(i=0;i<2;i++){
    if (class[i].g1>ave)
        fprintf(outputfile,"\n %d ",class[i].g1);
     else if (class[i].g2 > ave)
        fprintf(outputfile,"\n %d ",class[i].g2);}
  
  fclose(outputfile);    
   

  inputfile = fopen("test.txt","r");
  while (fscanf(inputfile,"%d ",&a)!=EOF)
    {
       printf("\n%s  %d ",a);
    }
 
  fclose(inputfile);  



/*for (i=0;i<3;i++)
    scanf ("%d %d %s %s",&(class[i].grade), &(class[i].number), class[i].name, 
    class[i].surname);

for (i=0;i<3;i++)
    printf ("\n%d %d %s %s\n",class[i].grade, class[i].number, class[i].name, 
    class[i].surname);*/

 
  
  system("pause");
  return 0;
  
}
