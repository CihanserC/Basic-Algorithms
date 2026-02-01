using System;

// String Search Program 

namespace ConsoleApp1
{
	class Program
	{
		public static void print(string text) {

			for (int i = 0; i < text.Length; i++)
			{
				Console.Write(text[i]);
			}

			Console.WriteLine("\n\n\n############### Welcome to the string search ###############");
		}

		public static int analysis(string input)
		{
			int result = 0;
			if (input.Contains("*") == true && input.Contains("-") == false)
			{
				result = 1;     // Star exists, dash does not.
			}
			else if (input.Contains("-") == true && input.Contains("*") == false)
			{
				result = 2;     // Dash exists, star does not.
			}
			else if (input.Contains("*") == true && input.Contains("-") == true)
			{
				result = 3;     // Star and dash both exist.
			}
			//Console.WriteLine("Analysis : " + result);

			return result;
		}

		public static void conclude(string input,string[] words)
		{
			int result = analysis(input);
			int star, dash;
			if (result == 1)
			{
				star = checkstar(input);
				if (star == 1)
				{
					find1(input, words, result);
				}
				else if (star == 2)
				{
					find2(input, words, result);
				}
				else if (star == 3)
				{
					find1(input, words, result);
				}
			}else if (result == 2)
			{
				dash = checkdash(input);
				if (dash == 1)
				{
					find1(input, words, result);
				}
				else if (dash == 2)
				{
					find2(input, words, result);
				}
				else if (dash == 3)
				{
					find1(input, words, result);
				}
			}else if (result == 3)
			{
				star = checkstar(input);
				dash = checkdash(input);

				find3(input,words);

			}else
			{
				Console.WriteLine("Error :Wrong input");
			}

		}

		public static int checkdash(string input)
		{
			int dash = 0;
			for (int i = 0; i < input.Length; i++)
			{
				if (input[i] == '-' && i == 0)
				{
					dash = 1;   // dash at beginning
				}
				else if (input[i] == '-' && i != 0 && i != input.Length - 1)
				{
					dash = 2;   // dash in middle
				}
				else if (input[i] == '-' && i == input.Length - 1)
				{
					dash = 3;   // dash at end
				}
			}
			//Console.WriteLine("Dash : " + dash);

			return dash;
		}

		public static int checkstar(string input)
		{
			int star = 0;

			for (int i = 0; i < input.Length; i++)
			{
				if (input[i] == '*' && i == 0)
				{
					star = 1;   // star at beginning
				}
				else if (input[i] == '*' && i != 0 && i != input.Length - 1)
				{
					star = 2;   // star in middle
				}
				else if (input[i] == '*' && i == input.Length - 1)
				{
					star = 3;   // star at end
				}
			}
			//Console.WriteLine("Star : " + star);

			return star;
		}


		public static void find1(string input, string[] words,int result)
		{   
			// for cases with only star or only dash at the beginning or end

			string restore = "";
			for (int i = 0; i < input.Length; i++)
			{
				if(result == 1) {
					if (input[i] != '*')
					{
						restore += input[i];
					}
				} else if(result==2) {
					if (input[i] != '-')
					{
						restore += input[i];
					}
				}

			}

			for (int i = 0; i < words.Length; i++)
			{
				if (result == 1){
					if (words[i].Contains(restore)){
						Console.WriteLine("Matching words : " + words[i]);
					}
				}else if (result == 2){
					if (words[i].Contains(restore) && restore.Length + 1 == words[i].Length){
						Console.WriteLine("Matching words : " + words[i]);
					}
				}

			}
		}

		public static void find2(string input, string[] words,int result)
		{
			// for cases with only star or only dash in between
			string restore = "";
			string restore2 = "";
			int index = 0;

			char c=' ';
			if(result==1){
				c = '*';
			}else if(result == 2){
				c = '-';
			}

			for (int i = 0; i < input.Length; i++)
			{
				if(input[i] != c) {
					restore += input[i];
				}
				else if(input[i] == c)
				{
					index = i;
					break;
				}
			}

			for (int i = index + 1; i < input.Length; i++)
			{
				restore2 += input[i];
			}

			for (int i = 0; i < words.Length; i++)
			{
				if (words[i].Contains(restore) && words[i].Contains(restore2))
				{
					Console.WriteLine("Matching words : " + words[i]);
				}
			}

		}

		public static void find3(string input, string[] words)
		{
			// for inputs with both star and dash

			string restore  = "" ;
			string restore2 = "" ;
			string restore3 = "" ;
			int index = 0;

			for (int i = 0; i < input.Length; i++)
			{
				if (input[i] != '*' && input[i] != '-')
				{
					restore += input[i];
				}
				else if (input[i] == '*' || input[i] == '-')
				{
					index = i;
					break;
				}
			}

			for (int i = index + 1; i < input.Length; i++)
			{
				if (input[i] != '*' && input[i] != '-')
				{
					restore2 += input[i];
				}
				else if (input[i] == '*' || input[i] == '-')
				{
					index = i;
					break;
				}
			}

			for (int i = index + 1; i < input.Length; i++)
			{
				restore3 += input[i];
			}


			for (int i = 0; i < words.Length; i++)
			{
				if (words[i].Contains(restore) && words[i].Contains(restore2) && words[i].Contains(restore3))
				{
					// Two "otursak" outputs in the "o-u*ak" input is not an error because "otursak" appears twice in the text,
					// so both are printed.
					Console.WriteLine("Matching words : " + words[i]);
				}
			}




		}

		public static void Main(string[] args)
		{
			string text = "oyuncak evi yıkıp yaksak yapsak da mı otursak yoksa yıkmasak onarsak da mı otursak eve";
			string[] words = text.Split(' ');

			print(text);

			Console.Write("\n\nEnter input string : ");
			string input = Console.ReadLine();
			conclude(input,words);



			Console.ReadKey();

		}
	}
}

