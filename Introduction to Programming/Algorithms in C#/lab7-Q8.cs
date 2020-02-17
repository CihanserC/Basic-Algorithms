using System;

namespace Project
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			//output : 1,7,12,5
			int[] numbers = new int[] { 1, 7, 7, 12, 1, 5, 1, 1, 12, 12, 12, 7, 1, 1 };
			int[] neaq = new int[14];
			int i, j;
			int n = numbers.Length;
			bool flag = true;

			for ( i = 0; i < numbers.Length; i++){
				for ( j = 0; j < numbers.Length; j++){
					if(i!=j && numbers[i] != numbers[j]){
						flag=false;
					}
				}
				if (flag == true){
					neaq[i] = numbers[i];
				}
				flag = true;
				Console.WriteLine((i+1)+". - "+neaq[i]);

			}
				Console.ReadKey();
		}
	}
}
