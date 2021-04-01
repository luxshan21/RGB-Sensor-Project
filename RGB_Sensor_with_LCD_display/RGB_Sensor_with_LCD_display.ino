#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);//RS,EN,D4,D5,D6,D7
int redled=11;
int greenled=12;
int blueled=13;

int value = A0;
int red;
int blue;
int green;

int redvalue;
int bluevalue;
int greenvalue;

int redout=A1;
int blueout=A2;
int greenout=A3;


void setup() {
  lcd.begin(16, 2);
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(blueled,OUTPUT);

  pinMode(value,INPUT);

  pinMode(redout,OUTPUT);
  pinMode(greenout,OUTPUT);
  pinMode(blueout,OUTPUT);

  Serial.begin(9600);
  
  

}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(" Color Detected ");//printing name 
  digitalWrite(redled,HIGH);
  delay(40);
  red=analogRead(value);
  delay(10);
  Serial.print("R=");
  Serial.print(red);
  digitalWrite(redled,LOW);

  digitalWrite(greenled,HIGH);
  delay(40);
  green=analogRead(value);
  delay(10);
  Serial.print("G=");
  Serial.print(green);
  digitalWrite(greenled,LOW);

  digitalWrite(blueled,HIGH);
  delay(40);
  blue=analogRead(value);
  delay(10);
  Serial.print("B=");
  Serial.print(blue);
  digitalWrite(blueled,LOW);

  if (red>green&&red>blue){
    redvalue=HIGH;
    lcd.setCursor(0, 1);  
    lcd.print("    RED Color   ");
    }
   else
   redvalue=LOW;

  if (green>red&&green>blue){
    greenvalue=HIGH;
    lcd.setCursor(0, 1); 
    lcd.print("   Green Color   ");
    }
  else
   greenvalue=LOW;

  if (blue>red&&blue>green){
    bluevalue=HIGH;
    lcd.setCursor(0, 1);
    lcd.print("   Blue Color   ") ;
    }
  else
   bluevalue=LOW;

 
  
  
  digitalWrite(redout,redvalue);
  digitalWrite(greenout,greenvalue);
  digitalWrite(blueout,bluevalue);
}
