using System;

namespace lab8_solutions
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			// 1. SORU
			/*
			bool[,] a = new bool[,] {{true, false, false, true, true},{false, false, false, true, false},
				{true, true, true, false, true},
				{false, true, false, false, true}};

			for(int i=0;i<a.GetLength(0);i++){
				
				for(int j=0;j<a.GetLength(1);j++){
					
					if(a[i,j] == true) {

						Console.Write ("*");

					}else if(a[i,j] == false){
						Console.Write ("-");
					}

				}
				Console.WriteLine();
			
			}

			Console.ReadKey();

			*/

			// 2. SORU
			/*

			int[,] a = new int[,] {{5, 4, 0, 2, 8, 0},{0, 5, 7, 1, 3, 5},{12, 3, 6, 0, 2, 0}};

			int counter = 0;


			for (int i = 0; i < a.GetLength (0); i++) {

				for (int j = 0; j < a.GetLength (1); j++) {
					if (a [i, j] == 0) {
						counter++;

					}
				}
			}

				Console.WriteLine("zero number in array : " +counter);


				Console.ReadKey();
				
				*/


			// 3. SORU

			/*
			 
			char[,] a = new char[,]{{'S', 'O', 'S'},{'O', 'S', 'O'},{'S', 'O', 'S'}};
			bool flag = true;
			for (int i = 0; i < a.GetLength (0); i++) {

				for (int j = 0; j < a.GetLength (1); j++) {
					
					if (a [i, j] != 'S' && a [i,j] != 'O') {
						flag = false;
					}
				}
			}
			Console.WriteLine("Result: "+flag);

			Console.ReadKey();
			
			*/

			// 4. SORU

			/*
			int[,] a = new int[,] { { 1, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0 }, { 0, 0, -1, 0, 0 }, { 0, 0, 0, -1, 0 }, { 0, 0, 0, 0, 1 } };


			bool flag = true;
			for(int i = 0; i < a.GetLength (0); i++){

				for(int j = 0; j < a.GetLength (1); j++){

					if (a [i, i] != 1 && a [i, i] != -1) {
						flag = false;
					} else if (i != j && a [i, j] != 0) {
						flag = false;
					}
				}
			}


			Console.WriteLine("Result: "+flag);

			Console.ReadKey();

			*/


			//	5. SORU

			/*


			int[,] a = new int[,]{ { 4, 0, 0, 0, 0 }, { 0, 4, 0, 0, 0 }, { 0, 0, 4, 0, 0 }, { 0, 0, 0, 4, 0 }, { 0, 0, 0, 0, 4 } };
			bool flag = true;

			for(int i = 0; i < a.GetLength (0); i++){

				for(int j = 0; j < a.GetLength (1); j++){

					if(a [i, i] != 4){
						flag = false;
					} else if(i != j && a [i, j] != 0){
						flag = false;
					}
				}
			}

			Console.WriteLine("Result: "+flag);

				Console.ReadKey();
			*/

			// 6. SORU
			/*

			int[,] a = new int[,] {{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,0,0,0,0}};
			bool flag = true;

			for(int i = 0; i < a.GetLength (0); i++){

				for(int j = 0; j < a.GetLength (1); j++){

					if((i+j)== 4 && a[i,j] != 1){
						flag = false;
					} else if((i+j)!= 4 && a[i,j] != 0){
						flag = false;
					}
				}
			}


			Console.WriteLine("Result: "+flag);


			Console.ReadKey();


			*/

			// 7. SORU

			/*
			 
			int[,] a = new int[,] {{0, 2, -1},{-2, 0, -4},{1, 4, 0}};
			bool flag = true;

			for(int i=0;i<a.GetLength(0);i++){

				for(int j=0;j<a.GetLength(1);j++){

					if(a[i,j]!=(-1*a[j,i])){
						flag = false;
					}if(a[i,i]!=0){
						flag = false;
					}
				}
			}


			Console.WriteLine("Result: "+flag);


			Console.ReadKey();

			*/

			// 8. SORU

			/*

			int[,] a = new int[,] {{1, 0, 0, 0, 0},{7, 8, 0, 0, 0},{9, 1, 1, 0, 0},{9, 3, 9, 2, 0},{5, 6, 8, 1, 5}};
			bool flag = true;
			int counter = 0;
			for(int i=0;i<a.GetLength(0);i++){

				for(int j=0;j<a.GetLength(1);j++){

					if(a[i,j] !=0){
						counter++;
					}

				}

				if(counter != i+1){
					flag = false;
				}
				counter = 0;
			}

			Console.WriteLine("Result: "+flag);

			Console.ReadKey();

			*/


			}
		}
	}

