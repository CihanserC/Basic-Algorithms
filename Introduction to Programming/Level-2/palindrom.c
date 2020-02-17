#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0 

// Palindrome number checker.

int divisor(int a,int len){
  if(len<2)
    return a;
  else
    return divisor(a/10,len-1);
}


int multiplier(int a,int len){
  if(len<2)
    return a;
  else
    return multiplier(a*10,len-1);
}

int digitCounter(int n) //iterative digitCounter function , try recursive one
{
 int count=0;
  while(n!=0)
  {
      n=n/10;             /* n=n/10 */
      count++;
  }
  return count;
}
          //444  //33
bool isPalindrome(int num, int len)
{
  int left,right,mult,res;
    if(len < 2)
      return true;
    else{
      //14441   1
       right=num%10;
       printf("right is : %d\n",right);
      //14441
       left=divisor(num,len); //1
       
       printf("left is : %d \n",left);
       

       mult=multiplier(left,len);
       printf("multiplier is : %d\n",mult);
       res=(num-mult)/10;
       printf("res is : %d\n",res);
       printf("left == right %d\n",left==right);
       printf("isPalindrome %d\n",isPalindrome(res, len-2));
       
       //left : 1                      //444   3
  
      return left==right && isPalindrome(res, len-2);
    }
} 

int main()
{
    int num,length;// num 14441 
    printf("Enter Number ");
    scanf("%d",&num); //14441
   
    length = digitCounter(num); //5
    printf("length is : %d \n" , length);
    if(isPalindrome(num,length)){
      printf("%d Palindrome",num);
    }else{
    printf("%d Not Palindrome",num);
    }
  
    return 0;
}

