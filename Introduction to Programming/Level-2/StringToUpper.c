#include <stdio.h>
#include <stdlib.h>

//Converting lowercase letters to uppercase letters


void convertToUppercase( char *sPtr ); /* prototype */
int main()
{
   char string[] = "characters and $32.98"; /* initialize char array */
   printf( "The string before conversion is: %s", string );
   convertToUppercase( string );
   printf( "\nThe string after conversion is: %s\n", string ); 

   system("PAUSE");
   return 0;    
}

/* convert string to uppercase letters */
void convertToUppercase( char *sPtr )
{
   while ( *sPtr != '\0' ) 
   { /* current character is not '\0' */ 
      if ( islower( *sPtr ) )     /* if character is lowercase, */
        *sPtr = toupper( *sPtr ); /* convert to uppercase */
   
      ++sPtr;  /* move sPtr to the next character */
   } 
   
} /* end function convertToUppercase */

