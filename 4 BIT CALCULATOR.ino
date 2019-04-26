
#include <LiquidCrystal.h>                                         
LiquidCrystal lcd(41,43,45,47,49,51); // Allocate pins to LCD
String a;
String b;                              
String c;
String name = ""; 

void setup(){                                     /*defining input and  output arduino pins*/

  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  pinMode(22,INPUT);
  pinMode(24,INPUT);
  pinMode(26,INPUT);
  pinMode(28,INPUT);
  pinMode(30,INPUT);
  lcd.begin(16,2);
  
}

float bintodec(float arr[])                         /*function to convert binary to decimal*/
{
float Dec=0.00;
for(int i=0;i<=4;i++)
{
  Dec+=arr[i]*(pow(2,4-i));
}

return Dec;
}

void convertDecToBin(int Dec, boolean Bin[]) {      /*function to convert decimal to binary*/
  for(int i = 3 ; i >= 0 ; i--) {
    if(pow(2, i)<=Dec) {
      Dec = Dec - pow(2, i);
      Bin[4-(i+1)] = 1;
    } else {
    }
  }
}


float bintodec1(float arr[])      /*function to convert binary to decimal*/
{
float Dec=0.00;
for(int i=0;i<=1;i++)
{
  Dec+=arr[i]*(pow(2,1-i));
}

return Dec;
}

void loop()
{  
   
      while(Serial.available()==0){       /*taking input from serial monitor*/
      }
      a=Serial.readString();
      Serial.println(a.toInt());
     
         boolean temp[4]={0,0,0,0};
         convertDecToBin(a.toInt(),temp);
         
         digitalWrite(2,boolean(temp[3]));  /*giving input to arduino*/
         digitalWrite(3,boolean(temp[2]));
         digitalWrite(4,boolean(temp[1]));
         digitalWrite(5,boolean(temp[0]));
         
         
          while(Serial.available()==0){     /*taking second number input from serial monitor*/
          }
          b=Serial.readString();
          Serial.println(b.toInt());
         
         boolean temp1[4]={0,0,0,0};
         convertDecToBin(b.toInt(),temp1);
         
         
         digitalWrite(6,boolean(temp1[3]));
         digitalWrite(7,boolean(temp1[2]));
         digitalWrite(8,boolean(temp1[1]));
         digitalWrite(9,boolean(temp1[0]));
         
         Serial.println("0 ->Addition");
         Serial.println("1-> Multiplication");
         Serial.println("2-> Subtraction");
         Serial.println("3 ->Division");
         
         while(Serial.available()==0){      /*taking operation input from arduino serial monitor*/
          }
          c=Serial.readString();
          Serial.println(c.toInt());
         
         boolean temp2[4]={0,0,0,0};
         convertDecToBin(c.toInt(),temp2);
         
         digitalWrite(10,boolean(temp2[2]));
         digitalWrite(11,boolean(temp2[3]));
         
        int a1 = digitalRead(22);     /*reading output of rasberry pi from input pins of arduino*/
        int a2 = digitalRead(24);
        int a3 = digitalRead(26);
        int a4 = digitalRead(28);
        int a5 = digitalRead(30);  
         
         
        float output[5]={a5,a4,a3,a2,a1};
        float ans=bintodec(output);
        
        lcd.setCursor(0,0);
        lcd.print("=");
        lcd.print(ans);       /*printing the output on the lcd display*/
        
        Serial.println(ans);
        delay(10);
        while(Serial.available()>0){}
       
       
    
    
    }
  
