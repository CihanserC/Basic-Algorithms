
int main()
{  
  
    int i;

    int count = 0;

    double pi = 4.0;

 

    for ( i = 3; i <= 1000; i += 2) 
	{

        if ( count % 2 == 0 )
		 {

       		 pi -= 4.0 / (double)i;

       		 printf( "%0.2f\t", pi);

        }

        else
		 {

     	    pi += 4.0 / (double)i;

        	printf( "%0.2f\t", pi);

        }

        count++;

}

    return 0;

}

