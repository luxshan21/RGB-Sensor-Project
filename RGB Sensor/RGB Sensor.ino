int redled=2;
int greenled=3;
int blueled=4;

int value = A0;
int red;
int blue;
int green;

int redvalue;
int bluevalue;
int greenvalue;

int redout=8;
int blueout=9;
int greenout=10;


void setup() {
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
    }
   else
   redvalue=LOW;

  if (green>red&&green>blue){
    greenvalue=HIGH;
    }
  else
   greenvalue=LOW;

  if (blue>red&&blue>green){
    bluevalue=HIGH;
    }
  else
   bluevalue=LOW;

 
  
  
  digitalWrite(redout,redvalue);
  digitalWrite(greenout,greenvalue);
  digitalWrite(blueout,bluevalue);
}
