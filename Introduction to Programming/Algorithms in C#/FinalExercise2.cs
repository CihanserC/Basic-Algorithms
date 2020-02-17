using System;

namespace finalex2_v3
{
	class MainClass
	{
		// 1. soru
		static string reverseorder(string str){

			string result= "";
			string[] word = str.Split (' ');

			for(int i=word.Length-1;i>=0;i--){
				result += word [i];
				result += " ";
			}

			return result;
		}


		// 2. soru

		static bool paritychecker(int[,] array){
			int row=0;
			int column = 0;
			bool flag = true;

			for(int i=0;i<array.GetLength(0);i++){

				for(int j=0;j<array.GetLength(1);j++){

					row    += array [i, j];
					column += array[j,i];


				}
				if(row %2 ==1 || column %2 ==1){
					flag=false;
				}
				row = 0;
				column = 0;
			}


			return flag;
		}

		// 3. soru
		static int sumofseries(int n){

			int result = 0;
			string c = "";

			for (int i = 0; i < n; i++) {
				c += "1";
				result += Convert.ToInt32(c);
			}

			return result;
		}

		// 4. soru

		static void nonrepeated(string str){
			char c;
			int counter = 0;

			for(int i=0;i<str.Length-1;i++){
				c=str[i];
				if (str.Substring(i+1).Contains(c.ToString())==false) {
					Console.Write(c);
					counter++;
				}
				if (counter == 1) {
					break;
				}
			}
		}


		// 5. soru
		static void tribonacci(){

			int a, b, c;
			a = 1;
			b = 1;
			c = 2;
			int x = 0;
			for (int i = 0; i < 16; i++) {
				x = a + b + c;
				a = b;
				b = c;
				Console.Write(x+" ");
				c = x;
			}
		}


		// 6. soru

		static bool markov(double[,] arr){

			bool flag = true;
			double sum = 0;
			for(int i=0;i<arr.GetLength(0);i++){
				for(int j=0;j<arr.GetLength(1);j++){
					sum += arr [i, j];
				}
				if (sum != 1) {
					flag = false;
				}
				sum = 0;
			}
			return flag;
		}

		// 7. soru	

		static void ArmStrong(){

			int rem, sum, temp, tnum;
			for (int i=100; i <= 999; i++)
			{
				tnum = i;
				sum = 0;
				while (tnum > 0){

					rem = tnum % 10;
					temp = rem * rem * rem;
					sum = temp + sum;
					tnum = tnum / 10;
				}
				if (i == sum)
					Console.WriteLine(sum);
			}
		}

		// 8. soru		

		static string lowercase(string str){

			string result="";
			string rest = "";
			string firstletter;

			string[] word = str.Split(' ');

			for(int i=0;i<word.Length;i++){
				firstletter = word[i][0].ToString().ToUpper();


				rest = word[i].Substring(1);
				result += firstletter + rest + " " ;
			}

			return result;
		}


		//9. Soru

		static bool shiftmatrix(int[,] arr){

			bool flag = true;
			bool superdiagonal;
			int sum = 0;
			for(int i=0;i<arr.GetLength(0);i++){
				for(int j=0;j<arr.GetLength(1);j++){
					if (arr [0, 0] == 1 || arr [0, arr.GetLength (0)]==1) {
						// could be superdiagonal 
						if(arr[i,i]!=1){
							flag = false;
						}
					}else{
						// coulde be subdiagonal
						sum+= arr[j,i];
						if (sum > 1) {
							flag = false;
						}
					}
				}
			}


			return flag;

		}

		//10. Soru

		static string replace(string str){
			string result="";

			for (int i = 0; i < str.Length; i++) {

				if(str[i]=='a' || str[i]=='e' || str[i]=='o' || str[i]=='i' || str[i]=='u' ){
					result += "0";
				}else{
					result += "1";
				}
			}

			return result;
		}

		//11. Soru

		static bool zmatrix(int[,] arr){

			bool flag = true;

			for(int i=0;i<arr.GetLength(0);i++){
				for(int j=0;j<arr.GetLength(1);j++){

					if(i!=j && arr[i,j]>0){
						flag = false;
					}
				}
			}

			return flag;
		}

		//12. Soru

		static string replace2(int[] arr){

			string result = "";

			for (int i = 0; i < arr.Length; i++) {

				if(arr[i] %2 == 0  ){
					result += "0";
				}else{
					result += "1";
				}
			}

			return result;
		}


		//13. Soru	 

		static string shift2left(string str){

			string result = "";
			string[] word = str.Split(' ');

			for(int i=0;i<word.Length;i++){
				result +=  word[i].Substring(2) + word[i].Substring(0, 2) + " ";
			}
			return result;
		}

		//14. Soru


		static int obebof2int(int a,int b){
			int small;

			if(a>b){
				small = b;
			}else{
				small = a;
			}
			int max = 0; 

			for(int i=1;i<small-1;i++){

				if(a% i == 0 && b % i ==0){

					max = i; 
				}
			}


			return max;
		}

		// 15.soru

		static void anagram(){

			Console.WriteLine("Enter 1. string : ");
			string s1 = Console.ReadLine();
			Console.WriteLine("Enter 2. string : ");
			string s2 = Console.ReadLine();
			string temp = "";
			bool flag = true;
			for(int i=0;i<s1.Length;i++){
				temp = Convert.ToString(s1[i]);
				if(s2.Contains(temp)==false) {
					Console.WriteLine ("Not-Anagram!");
					flag = false;
					break;
				}
			}
			if(flag==true){
				Console.WriteLine ("Anagram!");
			}
		}



		public static void Main (string[] args){


			string s1 = "bugün hava sıcak rüzgar kuvvetli";
			string s2 = "hava hem sıcak hem de rüzgarlı";
			//Console.WriteLine(reverseorder(s1));


			int[,] a = new int[,] {{ 1, 0, 1, 0 },
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 1 },
				{ 0, 1, 0, 1 }
			};


			//Console.WriteLine(paritychecker(a));

			//Console.WriteLine(sumofseries(5));

			//tribonacci ();
			double[,] array = new double[,] {{ 0.2, 0.8, 0 },
				{ 0.4, 0, 0.6 },
				{ 0.5, 0.35, 0.15 }
			};

			//Console.WriteLine(markov(array));

			//armstrong (300);

			//Console.Write (lowercase (s1));

			//Console.Write(replace ("derya"));

			int[] b = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 

			//Console.Write(replace2(b));

			//Console.Write(obebof2int(18,24));

			//anagram();


			//Console.Write(shift2left(s1));

			//nonrepeated(s2);

			Console.ReadKey ();
		}
	}
}
