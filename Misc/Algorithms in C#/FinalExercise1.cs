using System;

namespace finalex1_v2
{
	class MainClass
	{// 1. soru
		static void print(string input){

			string s2;
			for(int i=0;i<input.Length;i++){

				s2 = input.Substring (0,i+1);
				Console.WriteLine (s2);
			}

		}
		// 2. soru

		static bool tridiagonal(int[,] m){

			bool flag = true;

			for(int i=0; i<m.GetLength(0) ; i++){

				for(int j=0; j<m.GetLength(1) ; j++){

					if(i==j && m[i,j] == 0){
						flag = false;
					}else if(i==j+1 && m[i,j]==0){
						flag = false;
					}else if(i==j-1 && m[i,j]==0){
						flag = false;
					}
				}
			}
			return flag;
		}

		// 3. soru

		static 	void position(int n){

			int[] a = new int[] {1, 12, 10, -1, 11, 14, 4};

			for(int i=0;i<a.Length;i++){

				if(a[i] == n){
					Console.WriteLine((i+1)+". Element");	
				}
			}

		}

		// 4. soru

		static bool paranthesis(string str){

			int c1 = 0;
			int c2 = 0;
			bool flag = true; 
			for(int i=0;i<str.Length;i++){

				if (str [i] == '(') {
					c1++;
				}else if(str [i] == ')'){
					c2++;
				}

			}
			if (c1 != c2) {
				flag = false;
			}

			return flag;

		}

		// 5 . soru

		static 	bool placeOfQueens(char[,] arr){
			bool flag=true;
			int counter = 0;

			for(int i=0;i<arr.GetLength(0);i++){
				for(int j = 0; j < arr.GetLength (0); j++){

					if(arr[i,j]=='Q'){
						counter++;
					}

				}
				if( counter > 1 ){
					flag = false;
				}
				counter = 0 ;
			}


			return flag;
		}
		// 6. soru
		static string merge(string str1,string str2){
			string str="";

			for(int i=0; i<str1.Length ;i++){
				str += str1 [i];
				str += str2 [i];

			}

			return str;
		}

		// 7. soru

		static void bytes(int n){
			string bit = "01";

			for(int i=0;i<n;i++){
				Console.WriteLine("Order"+i+": "+bit);
				bit += bit;
			}

		}
		// 8. soru
		static void abundant(int number){
			int sum=0;

			for(int i = 1; i < number - 1; i++){

				if(number % 2 == 0) {
					sum += i; 
				}

			}
			if (sum > number) {
				Console.WriteLine ("Abundant!");
			} else {
				Console.WriteLine ("Not-Abundant!");
			}
		}

		// 9. soru

		static int sumofrow(int number, int[,] array){
			int sum=0;
			for (int i = 0; i < array.GetLength(1) ; i++){
				sum += array [number,i] ;
			}
			return sum; 
		}

		// 10. soru

		static void examresult(string s1,string s2){

			int correct = 0;
			int wrong = 0;
			int empty = 0;

			for (int i = 0; i < s2.Length; i++) {
				if (s1 [i] == s2 [i]) {
					correct++;
				} else if (s1 [i] == ' ') {
					empty++;
				} else {
					wrong++;
				}

			}
			Console.WriteLine ("Correct : "+correct +"\nWrong : "+wrong + "\nEmpty : " + empty);
		}

		// 11. soru
	
		static void commoninterval(){
			int[,] a = new int[,]  {{ 10, 15},
									{ 12, 17},
									{ 8 , 14}};
			int left = 0;
			int right = 999;
			for(int i=0;i<a.GetLength(0);i++){
				for(int j=0;j<a.GetLength(1);j++){
					if(j == 0 && a[i,j] > left){
						left = a[i,j];
					}else if(j == 1 && a[i,j]<right){
						right = a[i,j];
					}
				}
			}
			if(left<right){
				Console.WriteLine("["+left+","+right+"]");
			}else {
				Console.WriteLine("No common interval!");
			}

		}

		//12. soru

		static void sumrandom(){
			bool flag=true;
			while (flag == true) {
				Random random = new Random();
				int n1 = random.Next (0, 10);
				int n2 = random.Next (0, 20);

				Console.WriteLine(n1+" + "+n2+ " = ");
				int input = Convert.ToInt16(Console.ReadLine());
				if (input != n1 + n2) {
					flag = false;
				}
			}
			Console.WriteLine("Wrong answer!\n\nYou have exit the program.");

		}

		// 13. soru



		static bool alliterative(){

			string str = "Alice’s aunt ate two apples and acorns around August";
			str = str.ToLower();
			str = str.Replace(".","" ).Replace(",","").Replace("!","").Replace("?","");
			string[] wrds = str.Split(' ');
			bool flag = true;

			for (int i = 1; i< wrds.Length; i++)
			{
				if(!wrds[i].Substring(0, 1).Equals(wrds[0].Substring(0, 1)))
				{
					flag = false;
					break;
				}
			}

			return flag;
		}

		// 14. soru  

		static string piglatin(string str){

			string output = "";
			string[] words = str.Split(' ');
			for (int i = 0; i<words.Length; i++)
			{
				if ("aeiouAEIOU".IndexOf(words[i].Substring(0, 1)) >= 0){
					output += words[i] + " ";

				}
				else{
					output += words[i].Substring(1) + "-" + words[i].Substring(0, 1) + "ay ";

				}
			}
			return output;
		}

		// 15. soru

		static void ispresent(string str,string alpha){

			for(int i = 0; i < alpha.Length; i++){
				bool flag = false;
				for(int j=0;j<str.Length;j++){
					if(alpha[i] == str[j]){
						flag = true;
					}
				}
				if (flag == false){
					Console.Write(" "+alpha[i]);
				}
			}
		}





		public static void Main(string[] args)
		{
			
			string str = "algorithm";
			int[,] a = new int[,] {{1, 3, 0, 0, 0},{1, 4, 1, 0, 0},{0, 2, 2, 1, 0},{0, 0, 5, 3, 1},{0, 0, 0, 2, 4}};
			string str2 = "(a (b (c (d (e) f) g) h) (i (j (k) l) m) n)";
			char[,] chess = new char[,] {{'*','*','*','Q','*'}, {'*','Q','*','*','*'},{'*','*','*','*','Q'},{'*','*','Q','*','*'},{'Q','*','*','*','*'}};
			string st1 = "ayşe";
			string st2 = "hoca";
			string new_str = "";
			int[,] ar = new int[,] {{15, 0, 0, 10, 0, 5},{ 0, 11, 3, 0, 1, 0},{ 2, 0, 10, 6, 9, 0},{ 9, 0, 6, 0, 0, 4},{ 1, 4, 0, 0, 7, 0},{ 0, 0, 8, 5, 0, 0}};
			string student_answers = "AA BDBCACC";
			string correct_answers = "ADDCDBCACB";
			string stra1 = "Alice’s aunt ate apples and acorns around August";
			string stra2 = "Fred’s friends fried Fritos for Friday’s food";
			string str3 = "this program is supposed to automate the translation ınput to the program will be several english sentences";
			string str4 = "bugün hava çok güzel.deniz,kumsal ve güneş muhteşem olacak.";
			string alpha = "abcçdefgğhıijklmnoöprsştuüvyz";

			//***********************************************
			/*
			print(str);
			Console.WriteLine (tridiagonal(a));
			Console.WriteLine (paranthesis(str2));
			Console.WriteLine (placeOfQueens(chess));
			new_str = merge (st1,st2);
			Console.WriteLine (new_str);
			bytes(6);
			abundant(112);
			Console.WriteLine ("sum : "+sumofrow (1, ar));
			examresult(student_answers , correct_answers);
			sumrandom();
			Console.WriteLine(alliterative());
			ispresent (str4, alpha);
			position(14);
			Console.Write(piglatin(str3));
			*/
			commoninterval ();
			Console.ReadKey ();
		}
	}
}
