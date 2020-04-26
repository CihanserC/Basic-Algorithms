using System;

namespace ConsoleApp1
{
	class Program
	{

		public static void Main(string[] args){
			
			Console.ForegroundColor = ConsoleColor.Yellow;
			Console.WriteLine("##### JACKPOT MACHİNE #####\n");
			Console.ResetColor();
			Random random = new Random();
			int redcounter=0;
			int greencounter=0;
			int bluecounter=0;
			string stlet = default(string);
			for (int i= 0;i<3; i++){
				int colornum = random.Next(1,3);
				int num = random.Next(0, 5);
				char let = (char)('A' + num);

				if (colornum==1){
					Console.ForegroundColor = ConsoleColor.Red;
					Console.Write(let+" ");
					redcounter++;
				}else if (colornum == 2){
					Console.ForegroundColor = ConsoleColor.Green;
					Console.Write(let + " ");
					greencounter++;
				}else if (colornum == 3){
					Console.ForegroundColor = ConsoleColor.Blue;
					Console.Write(let + " ");
					bluecounter++;
				}
				stlet = stlet + let;
			}

			Console.ResetColor();
			Console.WriteLine("");

			int money = 0;
			Boolean sameletter = false;
			if (stlet [0] == stlet [1]) {
				if (stlet [0] == stlet [2]) {
					//Console.WriteLine ("All 3 letters are the same!");
					money = money + 22;
					sameletter = true;
				} else {
					Console.WriteLine ("2 letters are the same!");
				}
			
			} else if (stlet [0] == stlet [2]) {
				
				//Console.WriteLine ("\n2 letters are the same!");
			} else if (stlet [1] == stlet [2]) {
				//Console.WriteLine ("\n2 letters are the same!");
			} else {
				//Console.WriteLine ("\nAll letters are different!");
				//we have to check if letters are consecutive

			}
				
			//*********************************************************
			//the code part that checks if letters are consecutive.
			Boolean isconsecutive = false;


			if(stlet[0] == 'A'){
				if(stlet[1] == 'B'){
					if(stlet[2] == 'C'){
						isconsecutive = true;
					}

				}else if(stlet[1] == 'C'){
					if(stlet[2] == 'B'){
						isconsecutive = true;
					}
				}
			}else if(stlet[0] == 'B'){
				if(stlet[1] == 'A'){
					if(stlet[2] == 'C'){
						isconsecutive = true;
					}
				}else if(stlet[1] == 'C'){
					if(stlet[2] == 'A'){
						isconsecutive = true;
					}else if(stlet[2] == 'D'){
						isconsecutive = true;
					}
				}else if(stlet[1] == 'D'){
					if(stlet[2] == 'C'){
						isconsecutive = true;
					}
				}
			}else if(stlet[0] == 'C'){
				if(stlet[1] == 'A'){
					if(stlet[2] == 'B'){
						isconsecutive = true;
					}
				}else if(stlet[1] == 'B'){
					if(stlet[2] == 'A'){
						isconsecutive = true;
					}else if(stlet[2] == 'D'){
						isconsecutive = true;
					}
				}else if(stlet[1] == 'D'){
					if(stlet[2] == 'B'){
						isconsecutive = true;
					}else if(stlet[2] == 'E'){
						isconsecutive = true;
					}
				}else if(stlet[1]=='E'){
					if(stlet[2]=='D'){
						isconsecutive = true;
					}
				}
			}else if(stlet[0] == 'D'){
				if(stlet[1] == 'B'){
					if(stlet[2] == 'C'){
						isconsecutive = true;
					}
				}else if(stlet[1] == 'C'){
					if(stlet[2] == 'B'){
						isconsecutive = true;
					}else if(stlet[2] == 'E'){
						isconsecutive = true;
					}
				}else if(stlet[1] == 'E'){
					if(stlet[2] == 'C'){
						isconsecutive = true;
					}
				}
			}else if(stlet[0]=='E'){
				if(stlet[1]=='C'){
					if(stlet[2]=='D'){
						isconsecutive = true;
					}else if(stlet[1]=='D'){
						if(stlet[2]=='C'){
							isconsecutive = true;
						}
					}
				}
			}

			if(isconsecutive==true){
				//Console.WriteLine("Consecutive Letters!");
			}
			//*****************************************************

			//Console.WriteLine ("Red color number: "+redcounter);
			//Console.WriteLine ("Green color number: "+greencounter);
			//Console.WriteLine ("Blue color number: "+bluecounter);

			if(redcounter == 1 && greencounter== 1){
				
				//Console.WriteLine ("All colors are different!");
				if(sameletter==true){
					money = money - 2;
				}
				if(isconsecutive==true){
					money = 14;
				}
				if(isconsecutive==false && sameletter==false){
					money = 8;
				}

			}else if(redcounter==3){
				
				//Console.WriteLine ("All colors are red!");
				if(isconsecutive==true){
					money = 16;
				}
				if(isconsecutive==false && sameletter==false){
					money = 10;
				}

			}else if(greencounter==3){
				
				//Console.WriteLine ("All colors are green!");
				if(isconsecutive==true){
					money = 16;
				}
				if(isconsecutive==false && sameletter==false){
					money = 10;
				}
			}else if(bluecounter==3){

				//Console.WriteLine ("All colors are blue!");
				if(isconsecutive==true){
					money = 16;
				}
				if(isconsecutive==false && sameletter==false){
					money = 10;
				}

			}else{
				//Console.WriteLine ("Only 2 colors are the same!");
				//	Means any two colors are the same and one is different.
				if(sameletter==true){
					money = money - 4;
				}
				if(isconsecutive==true){
					money = 12;
				}
				
			}

			if (money > 0) {
				Console.ForegroundColor = ConsoleColor.Magenta;
				Console.WriteLine("\n\n\nCONGRATULATİONS!!! YOU WİN");
				Console.ResetColor();
			}

			Console.WriteLine("\nYou earned : $"+money);

			Console.ReadKey();
		}
	}
}