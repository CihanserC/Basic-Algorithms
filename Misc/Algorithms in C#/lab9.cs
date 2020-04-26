using System;

namespace lab9_v2
{
	class MainClass
	{

		// 1. SORU

		static void print3rd(){

			string str = "Bugün hava çok güzel";

			for(int i=0;i<str.Length;i+=3){
				Console.Write (str [i]);
			}
		}

		// 2. SORU
		static void exchange(){
			
			string s1  = "computerrrr";
			string s2  = "programming";

			string s1new = "";
			string s2new = "";
			string temp1;
			string temp2;


			for (int i=0; i < s1.Length ; i++){

				if (i == 3) {
					//temp1 = s1[i];
					//temp2 = s2[i];
					s1new += s2 [i];
					s2new += s1 [i];
				} else{
					s1new += s1 [i];
					s2new += s2 [i];
				
				}
			
			}

			Console.WriteLine("s1 : "+s1new+"\ns2 : "+s2new);

		}

		// 3. SORU 

		static void middleofstr(){

			string s1 = "computer";
			string s2 = "derya";
			int mid1,mid2;
			mid1 = s1.Length / 2 ;
			mid2 = s2.Length / 2;

			if (s1.Length % 2 == 1){
				Console.WriteLine("s1 : "+s1[mid1]);
			}else{
				Console.WriteLine("s1 : " + s1[mid1 - 1] + s1[mid1]);
			}
			if (s2.Length % 2 == 1){
				Console.WriteLine("s2 : "+s2[mid2]);
			}else{
				Console.WriteLine("s2 : " + s2[mid2 - 1] + s2[mid2]);
			}
		}

		// 4. SORU 

		// garip çevirse de mantığı böyle.

		static void genderconverter(){
		
			string str   = "he is so cheap - just like his daddy, isn’t he?";

			str = str.Replace("his","her").Replace("he","she");
			Console.WriteLine(str);
		}

		// 5. SORU

		static void longestword(){

			string str = "Bugün hava çok güzel";

			string[] words = str.Split(' ');

			int max = 0;

			string result = "";

			for (int i = 0; i < words.Length; i++)
			{

				if (words[i].Length > max) {

					max = words[i].Length;

					result = words[i];

				}

			}

			Console.WriteLine(result);
		}

		// 6. SORU

		static void reverseorder(){

			string str = "computer";

			for(int i=str.Length-1;i>=0;i--){
				Console.Write(str[i]);
			}
		}

		// 7. SORU
		static void reversewords(){
		

			string s1 = "The answer is true";
		
			string[] words = s1.Split (' ');
			string restore = "";

			for (int i = 0;i<words.Length; i++) {
			
				words [i] = reverseit(words[i]) + " ";
				Console.Write(words[i]);

			}
		}

		static string reverseit(string str){
			string result="";

			for(int i=str.Length-1;i>=0;i--){
				result+=str[i];
			}

			return result;
		}

		// 8. SORU

		static void hydroxide(){


		string str = "One of balancing chemical equation is sodium carbonate Na2CO3 + calcium hydroxide CaOH -> sodium hydroxide NaOH + calcium carbonate CaCO3.";

			string[] words = str.Split(' ');

			for(int i=0;i<words.Length;i++){

				if(words[i].Contains("OH")){
					Console.WriteLine(words[i]);
				}
			}
		}

		// 9. SORU	tam olmadı ???!?!
		/*
		static void pilish(){


			string str = "How I need a drink";
			string pi = "31415";
			int n;
			bool flag = true;
			string[] words = str.Split(' ');

			for (int i = 0; i < words.Length; i++) {
				n = Int16.Parse(pi[i]);
				if (words[i].Length != n) {
					Console.Write ("GİRDİ!!!");

					flag = false;
				}
			}
			if (flag == true) {
				Console.Write ("Pilish");
			} else if(flag==false){
				Console.Write ("Not Pilish");
			}
		}
		*/
		// 10. SORU			tam olmadı ?!?!?!?!?!?!
		/*
		static void majoritychar(){

			string s = "ECE ve EGE deeeeeeeeeermişim";
		
			char[] alphabet = new char[] 
			{'a','b','c','d','e','f','g','h','ı','i','j','k','l','m','n','o','p','q','r','s','t','u','v','y','z'};
		
			int[] alphabucket = new int[] {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			Console.WriteLine ("Alphabet :    "+alphabet.Length+"    alphabucket : "+alphabucket.Length);
			s = s.ToLower();
			int max = 0;
			char c=' ';
			for(int i = 0;i<s.Length;i++){

				for (int j = 0; j < alphabet.Length; j++) {
				
					if (s [i] == alphabet [i]) {
						alphabucket[i] += 1;
					}
				}

			}
			for(int i=0;i<alphabucket.Length;i++){
				if(alphabucket[i]>max){
					max = alphabucket[i];
					c = alphabet [i];
				}
			}
			Console.Write("Repetition number : "+max+"\nLetter : "+c);
		
		}
		*/
		// 11. SORU

		static void makeplural(){

			Console.Write("Enter a word :");
			string str = Console.ReadLine();
			string result = "";

			if (str [str.Length - 1] == 'y') {
				str = str.Substring(0,str.Length-1);
				result += str+"ies";
			} else if (str [str.Length - 1] == 's') {
				result += str + "es";
			} else if (str [str.Length - 1] == 'h') {
				if (str [str.Length - 2] == 'c' || str [str.Length - 2] == 's') {
					result +=str+"es";
				}
				
			} else {
				result += str+"s";
			
			}
			Console.WriteLine (result);

		}

		// 12. SORU

		static void matchesnecessary(){

			char[] alphabet = new char[] 
			{'a','b','c','d','e','f','g','h','ı','i','j','k','l','m','n','o','p','q','r','s','t','u','v','y','z'};

			int[] alphabucket = new int[] {1,2,3,1,5,1,1,1,6,6,3,2,1,2,3,4,4,1,2,3,2,1,2,3,3};

			Console.Write("Enter a word :");
			string str = Console.ReadLine();
			str = str.ToLower();
			int sum = 0;

			for(int i=0;i<str.Length;i++){
				
				for(int j=0;j<alphabet.Length;j++){
					
				if(str[i]==alphabet[j]){
						
					sum += alphabucket[j];
				}
				}
			}
			Console.WriteLine(sum);
		}


		static void Main(string[] args)
		{

			//print3rd ();

			//exchange ();

			//middleofstr ();

			//genderconverter ();

			//longestword ();

			//reverseorder ();

			//reversewords ();

			//hydroxide ();

			//pilish ();

			//majoritychar ();

			//makeplural ();

			//matchesnecessary ();

			Console.ReadKey();
		
		}
	}
}
