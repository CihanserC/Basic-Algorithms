using System;

namespace homework_3
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine("Enter size of array :");
			int n = Convert.ToInt16(Console.ReadLine());
			char[,] Array = new char[n, n];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					Random random = new Random();
					int num = random.Next(0, 3);
					char let = (char)('A' + num);
					Array[i, j] = let;
					Console.Write(Array[i,j]);
				}
				Console.WriteLine();
			}

			int counter = 0;
			int max = 0;
			char letter='*';
			for(int i=0;i<n ;i++)
			{
				for (int j=0;j<n ;j++)
				{
					if(Array[i,i] == Array[i,j])
					{
						counter++;
						letter = Array[i, j];
					}
					letter = Array[i, j];

					if (max < counter)
					{
						max = counter;
					}

				}
				counter = 0;


			}
			Console.WriteLine("Counter: "+max + " Letter: "+letter);


			Console.ReadKey();
		}
	}
}
