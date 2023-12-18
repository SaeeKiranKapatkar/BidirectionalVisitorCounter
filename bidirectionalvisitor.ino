#include <Wire.h>
#include <LiquidCrystal.h>
const int trigPin=6, echoPin=5, buzz=13;

LiquidCrystal lcd(12,11,10,9,8,7);
int counter = 0;
int currentState1 = 0;
int previousState1 = 0;
int currentState2 = 0;
int previousState2 = 0;
int inside = 0;
int outside = 0;

void setup()
{
// initialize the LCD
lcd.begin(16,2);
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzz, OUTPUT);
}

void loop()
{
lcd.setCursor(6, 0);
lcd.print("In: ");
lcd.setCursor(9, 0);
lcd.print("Out: ");
lcd.setCursor(0, 1);
lcd.print("T: ");
long duration;
int distance;
digitalWrite(trigPin, HIGH);
delayMicroseconds(2);
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance=duration*0.034/2;

if(distance<=2){
  digitalWrite(buzz, HIGH);
  tone(13, 262, 250);
  //delay(3000);
  currentState1=1;
}
else{
  digitalWrite(buzz, LOW);
  currentState1=0;
}

distance = (duration/2) / 29.1;
if (distance <= 9){
currentState1 = 1;
}
else {
currentState1 = 0;
}
delay(100);
if(currentState1 != previousState1){
if(currentState1 == 1){
counter = counter + 1;}
lcd.setCursor(14, 1);
lcd.print(counter);
inside = inside +1;}
lcd.setCursor(4, 0);
lcd.print(inside);
if (distance > 2 && distance <= 5){
    digitalWrite(buzz, HIGH);
    tone (13,262, 250);
currentState2 = 1;
}
else {
currentState2 = 0;
}
delay(100);
if(currentState2 != previousState2){
if(currentState2 == 1){
counter = counter - 1;}
lcd.setCursor(14, 1);
lcd.print(counter);
outside = outside +1;}
lcd.setCursor(13, 0);
lcd.print(outside);
lcd.setCursor(14, 1);
lcd.print(counter);
if (counter > 9 || counter < 0){
lcd.setCursor(14, 1);
lcd.print(counter);
delay(100);
lcd.clear();
}
}