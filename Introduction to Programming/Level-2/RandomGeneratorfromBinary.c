#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Random generator from the binary seed.

void randbin()              //the array that involves random ones and zeros.
{
    int i=0;
    int binarray[64];

    binarray[64]=rand()%2;
    
    for(i=0 ; i<64 ; i++)
    {
        printf("%d",rand()%2);

    }
}
                                //this part for integer functions
int bin2(int a)
 {
    int j;
    int binarray[64];
    int b,c=0,d=1,e;
    b=a;
    
    for(j=16;j<32;j++)
    {
        e = binarray[j]%10;
        c+=e*d;
        binarray[j] = binarray[j]/10 ; 
        d = d *2 ;
    }
    
        return c;
 }

int binary_decimal(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=0 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
   
    return decimal_num;
}

int binary_decimal3(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=32 ; i<48 ; i++)
    {
    
        rem = binarray[i]% 10;
        decimal_num = decimal_num + rem * base;
        binarray[i] = binarray[i]/ 10 ;
        base = base * 2;
        
        

    }
    return decimal_num;
}

int binary_decimal4(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=48 ; i<64 ; i++)
    {
    
        rem = binarray[i]% 10;
        decimal_num = decimal_num + rem * base;
        binarray[i] = binarray[i]/ 10 ;
        base = base * 2;
    }
    return decimal_num;
}

    //this part for character functions

int binary_decimal5(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=0 ; i<8 ; i++)
    {
        rem = binarray[i]% 10;
        decimal_num = decimal_num + rem * base;
        binarray[i] = binarray[i]/ 10 ;
        base = base * 2;
    }
    return decimal_num;
}

int binary_decimal6(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=8 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal7(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=8 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal8(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=8 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal9(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=8 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal10(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=8 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal11(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=8 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal12(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=8 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

                                    //this part for float function
int binary_decimal13(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=0 ; i<16 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal14(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=16 ; i<32 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}

int binary_decimal15(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=32 ; i<48 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}


int binary_decimal16(int num)  
{   int binarray[64],i;
    int binary_num,decimal_num = 0, base = 1, rem;
    binary_num =num;
    for(i=48 ; i<64 ; i++)
    {
    
            rem = binarray[i]% 10;
            decimal_num = decimal_num + rem * base;
            binarray[i] = binarray[i]/ 10 ;
            base = base * 2;
        
        

    }
    
    return decimal_num;
   
}


                                    
                                    

int main()
{
    
    srand(time(NULL));
    int select;
    int decimal_output;
    int binarray[16];
    int output2,output3,output4,output5;
    int output6,output7,output8,output9;
    int output10,output11,output12;
    int output13,output14,output15,output16;
        
    
    printf("\n Random binary numbers with 64 elements : \n \n");
    randbin();
    printf("\n\n 1 for float : \n 2 for integer : \n 3 for character : \n\t");
    scanf("   %d",&select);
    
    switch(select)
    {
        case 1 :
            {
                output13 = binary_decimal13(binarray[16]);
                output14 = binary_decimal14(binarray[32]);
                output15 = binary_decimal14(binarray[48]);
                output16 = binary_decimal14(binarray[64]);
                
                printf("Your random 1. float number is : %d.%d \n",output13,output14);
                
                printf("Your random 2. float number is : %d.%d \n",output15,output16);
                
                
                    //    FLOAT ICIN FONKSIYON YAZ!!!!
            
            
                break;
            }
        case 2 :
            {
                binary_decimal(binarray[16]);
                decimal_output = binary_decimal(binarray[16]);
                
                output2 = bin2(binarray[32]);
                output3 = binary_decimal3(binarray[48]); 
                output4 = binary_decimal4(binarray[64]);
                
                printf("Your random  1. integer number is : %ld \n",decimal_output);
                printf("Your random  2. integer number is : %ld \n",output2);
                printf("Your random  3. integer number is : %ld \n",output3);
                printf("Your random  4. integer number is : %ld \n",output4);
                
                break;
            }
        case 3 :
            {
                output5  = binary_decimal5(binarray[8]);    
                output6  = binary_decimal6(binarray[16]);
                output7  = binary_decimal7(binarray[24]);
                output8  = binary_decimal8(binarray[32]);
                output9  = binary_decimal9(binarray[40]);
                output10 = binary_decimal10(binarray[48]);
                output11 = binary_decimal11(binarray[56]);
                output12 = binary_decimal12(binarray[64]);
                
                printf("Your random 1. character is  : %c\n",output5);
                printf("Your random 2. character is  : %c\n",output6);
                printf("Your random 3. character is  : %c\n",output7);
                printf("Your random 4. character is  : %c\n",output8);
                printf("Your random 5. character is  : %c\n",output9);
                printf("Your random 6. character is  : %c\n",output10);
                printf("Your random 7. character is  : %c\n",output11);
                printf("Your random 8. character is  : %c\n",output12);
                

                    
                break;
            }   
            
        default : printf("you have entered invalid value!"); break;
                    
    }

    
}


