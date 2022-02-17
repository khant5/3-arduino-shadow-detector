#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
const int buttonPin = 7; // left button

const int buttonPin2 =8; // right button

int buttonState = 0; //right

int buttonState2 = 0;// left

Servo servoA;

int position = 0;

void setup() {
  
lcd.begin(16, 2);

servoA.attach(9); // servo at pin 9
servoA.write(5);
pinMode(buttonPin, INPUT); // left button

pinMode(buttonPin2,INPUT); // right button

}

void loop() {
 while(!(buttonState ==HIGH &&buttonState2 == HIGH))
 {
  lcd.setCursor (0,0);
lcd.print ("Right Button");
lcd.setCursor (0,1);
lcd.print ("Or left Button:");
  if(buttonState ==HIGH ||buttonState2 ==HIGH)
  {
    lcd.clear();
  }

buttonState = digitalRead(buttonPin);// left button

buttonState2 = digitalRead(buttonPin2); // right button

if(buttonState ==LOW && buttonState2==HIGH  && position < 150){

lcd.setCursor (0,0);
lcd.print ("            up");
servoA.write(position++);// go up until 150 

delay(5);

}

if(buttonState2 == LOW && buttonState==HIGH && position > 5){

lcd.setCursor (0,0);
lcd.print ("            down");

servoA.write(position--); // go down until pos 5

delay(5);

}
}
lcd.clear();
lcd.setCursor (0,0);
lcd.print ("code stopped");
lcd.setCursor (0,1);
lcd.print ("Press reset");
}
