using System;

namespace ConsoleApp1
{
    class Program
    {

        //1 .soru
        public static void Write(int till,int number){

            for(int i =0;i<number ;i++){
                for(int j=0;j<till ;j++){
                    Console.Write(j);
                }
                Console.WriteLine();
                
            }
        }


        //2 .soru

        public static bool İsmagic(int number)
        {
            bool flag;
            int num = number;
            int sum = 0;
            sum += num % 10;
            num = num / 10;
            sum += num;

            if (sum == 10)
            {
                Console.WriteLine("Yes!");
                flag = true;
            }
            else {
                Console.WriteLine("No!");
                flag = false;
            }

            return flag;
        }


        //3 .soru


        public static char[] compDNA(char[] str)
        {
            int len = str.Length;
            char[] reverse = new char[len];

            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == 'A')
                {
                    reverse[i] = 'T';
                }
                else if (str[i] == 'T')
                {
                    reverse[i] = 'A';
                }
                else if (str[i] == 'G')
                {
                    reverse[i] = 'C';
                }
                else if (str[i] == 'C')
                {
                    reverse[i] = 'G';

                }
            }

            return reverse;

        }

        // 4. soru     

        public static void shuffle(int[] array)
        {
            for(int i=0;i<array.Length/2 ;i++) {
                Console.Write(array[i]+""+array[array.Length-1-i]);

            }
        }

        // 5. soru

        public static int firsthalf(int midindex,int[] array) {
            int sum = 0;
            for (int i = 0; i < midindex; i++) {
                sum += array[i];
            }
            return sum;
        }



        public static int sechalf(int midindex, int[] array) {

            int sum = 0;
            for (int i = midindex+1; i < array.Length; i++)
            {
                sum += array[i];
            }
            return sum;
        }


        public static bool funcmain(int[] array) {
            bool flag;
            int middle = array.Length / 2;
            int f = firsthalf(middle, array);
            int s = sechalf(middle, array);

            if (f==s)
            {
                flag = true;
            }
            else {
                flag = false;
            }

            return flag;
        }

        // 6. soru
        
        public static int facto(int number)
        {
            int result = 1;
            for(int i=1;i<number ;i++) {
                result = result * i;
            }
            return result;
        }

        public static int power(int ground , int exp)
        {
            int result = 1;
            for (int i = 1; i < exp; i++){
                result = ground * i;
            }
            return result;
        }

        public static int powdivfacto(int x, int exp,int factorial)
        {
            int result;
            result = power(x, exp) / facto(factorial);
            return result;

        }

        public static int calsin(int degree)
        {
            int result=0;
            int k;
            int counter = 1;
            for (int i=3;i<9 ;i+=2) {
                if (counter % 2 == 0)
                {
                    k = 1;
                }
                else {
                    k = -1;
                }
                result += k*(power(degree, i) / facto(i));


                counter++;
            }

            result = degree - result;

            return result;

        }

        // 7.soru

        public static double std(int[] array)
        {
            double result = 0;
            double sum = 0;
            double sum2 = 0;
            double x;
            for(int i=0;i<array.Length ;i++){

                sum += array[i];
                sum = sum / array.Length;   

            }

            for (int i = 0; i < array.Length; i++){

                int x=array[i] - sum;
                sum2+=power(x,2);
            }
            sum2 = sum2 / 5;
            result = Math.Sqrt(sum2);

            return result;
        }

        // 8.soru

        public static double harmonicmean(int[] array)
        {
            double result = 0;
            int n = array.Length;
            for (int i = 0; i < array.Length; i++){
                result += 1/array[i];
            }
            result = n / result;
            return result;
        }

    
        public static void Main(string[] args){

            char[] s = new char[6] {'T','A','A','C','G','T' };
            int[] array = new int[6] {1,2,3,4,5,6 } ;
            int[] numbers = { 2, 4, 16, 3, 7, 12 };
            int[] num = new int[] { 3,12,9,4,2};

            Write(6,5);
            İsmagic(91);
            char[] c = compDNA(s);
            Console.WriteLine(c);
            shuffle(array);
            funcmain(numbers);
            funcmain(numbers);
            calsin(30);
            std(array);
            Console.ReadKey();

        }
    }
}
