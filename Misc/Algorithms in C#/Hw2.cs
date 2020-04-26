using System;

namespace homework_2
{
	class MainClass
	{
		 public static int factorial(int value){
			int factorial = 1;
			for (int i = 1; i <= value; i++)
			{
				factorial *= i;
			}
			return factorial;

		}
		public static int findmax(int first,int second){
			if (first > second) {
				return first;	
			}else{
				return second;
			}
		}
		public static int exponential(int bottom,int exp){
			int result = 1;
			for (int i = 0; i < exp; i++) {
				result = result * bottom ; 
			}
			return result;
		}
		public static double isEven(int increment,double value){
			if (increment != 0) {
				if (increment % 2 == 1) {
					return value;
				} else if (increment % 2 == 0) {
					return value * (-1);
				}
			}
				return value;
			
		}

		public static void Main (string[] args)
		{

			int fact=5;				// faktoriyel değeri belirler
			int coefficient=3 ; 	// x li terimin katsayısı
			int exp=2;				// x li terimin üssü
			int formula;
			double pay;
			double payda;
			double result2 = 0; 	    
			double result3 = 0;  		
			int n=0;
			Console.WriteLine("Enter x number : ");
			int x = Convert.ToInt16(Console.ReadLine());

			for(int i=2;i<17;i++){
				
				formula = coefficient * exponential(x,exp); 

				pay = findmax(formula,factorial(fact));

				for(int j=2+n;j<i;j=j+2){

					result2 = result2 + exponential(j,i);
				}
				n = n + 2;
				payda = result2;
				double k = pay / payda;
				result3 = result3 + isEven(i,k);;
				2
				fact +=  2;
				coefficient +=  5;
				exp += 4;
			}


			Console.WriteLine("\nThe Answer : "+result3);

			Console.ReadKey();
		}
	}
}
