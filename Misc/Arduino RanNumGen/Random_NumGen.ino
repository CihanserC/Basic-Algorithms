#include"math.h"

int a = 9; // Defined pins
int b = 8;
int c = 5;
int d = 6;
int e = 7;
int f = 10;
int g = 11;
int dp = 4;

int seed;

void setup() {
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  seed = random(100,999);
  Serial.print("Seed = ");
  Serial.print(seed);
  DashedLine();
  Serial.print("\t\t*****\tINFO\t*****\n");

  Serial.print("\n\nAlgorithm:\n1-Midsquare\n2-LCG\n");
  Serial.print("\nMode:\n1-constantly shows random number untill user enter any input to stop.");
  Serial.print("\n2-Program constantly producing random number when user entered input it stops and shows the last produced number.");
  Serial.print("\n3-User just get only one random number for one time.");
  Serial.print("\n4-User enters that how many random number wants.");
  DashedLine();

  Serial.print("Please Enter the algorithm:   1-Midsquare     2-LCG\n");

}

void loop(){

 int alg,result,mode;   // alg: 1,2  mode: 1,2,3,4
 

 
 if(Serial.available() > 0){     // Alg scanf
    
  delay(500);
  alg = Serial.parseInt();
  Serial.print("Alg : ");
  Serial.print(alg);
  
  
  delay(1000);
  
   if(Serial.available() > 0) {    // Mode scanf


      Serial.print("\nPlease Enter the mode:   1 For 1.Mode    2 For 2.Mode 3 For 3.Mode 4 For 4.Mode \n");
      delay(2000);
      mode = Serial.parseInt();
      Serial.print("Mode : ");
      Serial.print(mode);
        // iflere mode u implemente et. ve 2 mod fonksiyonu yaz.
      if(alg == 1 && mode == 1){
  
        Serial.print("\nMidsquare selected");
        Serial.print("\n1.Mode selected");
        DashedLine();

        Mode1(alg,seed);
        
      }else if(alg == 1 && mode == 2){
        Serial.print("\nMidsquare selected");
        Serial.print("\n2.Mode selected");
        DashedLine();
        Mode2(alg,seed);

       }else if(alg == 1 && mode == 3){
        
         Serial.print("\nMidsquare selected");
         Serial.print("\n3.Mode selected");
         DashedLine();
        
         result = midsqr(seed);
         Serial.print("Random number is = ");
         Serial.println(result);
         
         PrintNum(result,mode);

       }else if(alg == 1 && mode == 4){
        
         Serial.print("\nMidsquare selected");
         Serial.print("\n4.Mode selected");
         DashedLine();
        
         result = midsqr(seed);
         
         Mode4(alg,seed);
         PrintNum(result,mode);

       }
      else if(alg == 2 && mode == 1){
  
        Serial.print("\nLCG selected");
        Serial.print("\n1.Mode selected");
        DashedLine();

        Mode1(alg,seed);

        result = Lcg(seed);
        Serial.print("Random number is = ");
        Serial.println(result);
     
        }else if(alg == 2 && mode == 2){
          
         Serial.print("\nLCG selected");
         Serial.print("\n2.Mode selected");
         DashedLine();
         Mode2(alg,seed);
        
       }else if(alg == 2 && mode == 3){
        
         Serial.print("\nLCG selected");
         Serial.print("\n3.Mode selected");
         DashedLine();
         
         result = midsqr(seed);
         Serial.print("Random number is = ");
         Serial.println(result);
         
         PrintNum(result,mode);
         
       }else if(alg == 2 && mode == 4){
        
         Serial.print("\nLCG selected");
         Serial.print("\n4.Mode selected");
         DashedLine();
         Mode4(alg,seed);
         result = midsqr(seed);
         
         
         
         PrintNum(result,mode);
         
       }
  
  
      }

    }
    delay(1000);
 }

int midsqr(long int lseed){
  
   long int rnum;

    lseed = lseed * lseed;
    lseed = lseed / 100; 
    lseed = lseed % 1000;   // number has to be between 1-1000
    rnum = lseed;
    return rnum;
}

int Lcg(long int lseed){    //Linear congruential generator(LCG)

    long int resnum;
    
    int a = random(1,1000);     // int number between 1-1000
    //Serial.print("\n a is = ");
    //Serial.print(a);
    
    int c = random(1,1000);    // int number between 1-1000
     //Serial.print("\n c is = ");
     //Serial.print(c);

    lseed = (a*lseed+c) % 1000;  //  maximum random number limit is 999   
    resnum = lseed;
    return resnum;
}
  void Mode1(int algorithm,long int mseed){
    
   //Show random numbers untill user stops it with input 1 .

    int result;
    int seed = mseed;
    int stopcode;
   
    Serial.print("\nPress 1 to stop.\n");

     while(true){    // sonsuz döngü
        if(algorithm == 1){

         result = midsqr(seed);
         seed = random(100,999);
         Serial.print("Random number is = ");
         Serial.println(result);
         PrintNum(result,1);
          delay(2000);
            if(Serial.available()){
              stopcode = Serial.parseInt();
              Serial.print("Stop : ");
              Serial.println(stopcode);
              if(stopcode == 1 ){
                break;  
                }
              
              }
      
      
       }else if(algorithm == 2){
        
          result = Lcg(mseed);
          seed = random(100,999);
          PrintNum(result,1);
          Serial.print("Random number is = ");
          Serial.println(result);
          delay(300);

          if(Serial.available()){
              stopcode = Serial.parseInt();
              Serial.print("Stop : ");
              
              if(stopcode == 1 ){
                break;  
                }

            }

          }
   }
   DashedLine();
  }

  void Mode2(int algorithm,long int mseed){
     // sürekli sayı üretip kullanıcı tuşa basınca durup son sayıyı yazdırsın
      
      int result;
      int sseed = mseed;
      int stopcode;
      Serial.println("Press 1 to stop and get random number");
       while(true){
        if(algorithm == 1){
          
          result = midsqr(sseed);
          sseed = random(100,999);
          PrintNum(result,2);
          //Serial.print("Random number is = ");
          Serial.println(result);
          delay(200);

          if(Serial.available()){
              stopcode = Serial.parseInt();
            
              if(stopcode == 1 ){
                break;  
                }
           }
          
           
       }else if(algorithm == 2){
          
          result = Lcg(mseed);
          seed = random(100,999);
          PrintNum(result,2);
          //Serial.print("Random number is = ");
          Serial.println(result);
          delay(200);
       
          if(Serial.available()){
              stopcode = Serial.parseInt();
              if(stopcode == 1 ){
                break;  
                }
           }
         
           
       }

    }
     Serial.print("Random number is = ");
     Serial.println(result);
     PrintNum(result,1);
     DashedLine();
  }

  void Mode4(int algorithm,long int mseed){

      int result;
      int seed = mseed;
      int number;
    Serial.print("\nHow many random numbers do you want? :");
    delay(2000);
    
    if(Serial.available()){
       number = Serial.parseInt();
    }
    Serial.println(number);
    delay(1000);
    
    while(number>0){

      if(algorithm == 1 ){

          result = midsqr(seed);
          seed = random(100,999);
          PrintNum(result,4);
          Serial.print("Random number is = ");
          Serial.println(result);
          delay(1000);
      
      }else if(algorithm == 2){
        
          result = Lcg(mseed);
          seed = random(100,999);
          PrintNum(result,4);
          Serial.print("Random number is = ");
          Serial.println(result);
          delay(1000);
        
        }
      number--;
           
      } 
    DashedLine();
   }

        
void DashedLine()
{
  Serial.println("\n-----------------------------\n");
}

void timerdecide(int mode){
  
    if(mode == 2){
    delay(150);  
    }else{
      delay(800);
     }
  }

void print7sgm(int num, int mode){

  if(num == 0){

     // Prints 0

  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  timerdecide(mode);

  

   }else if(num == 1 ){

     // Prints 1

  digitalWrite(a, LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  timerdecide(mode);

  }else if(num == 2){

     // Prints 2

  digitalWrite(a, HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  timerdecide(mode);
  
  }else if(num == 3){

     // Prints 3

  digitalWrite(a, HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  timerdecide(mode);
    
  }else if(num == 4){

     // Prints 4

  digitalWrite(a, LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  timerdecide(mode);
  

  }else if(num == 5){

   // Prints 5

  digitalWrite(a, HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  timerdecide(mode);
  
  }else if(num == 6){

   // Prints 6

  digitalWrite(a, HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  timerdecide(mode);
  
  }else if(num == 7){
       
   // Prints 7

  digitalWrite(a, HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  timerdecide(mode);
  
  }else if(num == 8){

    // Prints 8

  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  timerdecide(mode);
  
  }else if(num == 9){

    // Prints 9
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW); 
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  timerdecide(mode); 
  }
  
}

void closeligth(){
    
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);

    
}

int getlength(int number){

  int digitnum =0;
  
  while(number!= 0){
    
     number = number /10;
     digitnum++;
    }
  
  return digitnum;
}


int PrintNum(int ranum,int mode){

  int digitnumber = getlength(ranum);
  int i=0;
  int r2 = ranum ;
  int remainder;
  int A[3];
  
  while(digitnumber != 0){

      remainder = r2 % 10 ; 
      r2 = r2 / 10 ;
      A[digitnumber-1] = remainder ; 
      digitnumber--;
    }

    for(i = 0;i<3;i++){
      print7sgm(A[i],mode);  
    }

    closeligth();
  
  }

  

    
