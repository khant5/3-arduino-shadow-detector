int sensorValue;
int sensorLow=1023;
int sensorHigh=0;
const int ledPin=2;
const int yellowpin=3;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(yellowpin,OUTPUT);
  digitalWrite(yellowpin,LOW);
pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);
while(millis()<1000){
sensorValue=analogRead(A0);
if(sensorValue>sensorHigh){
   sensorHigh=sensorValue;
  
  }
 if(sensorValue<sensorLow){
  sensorLow=sensorValue; 
 }
 }

}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue=analogRead(A0);
int pitch=map(sensorValue,sensorLow,sensorHigh,50,300);
if(pitch<0)
{
  
tone(8,pitch+500,20);
digitalWrite(yellowpin,HIGH);
  digitalWrite(ledPin,HIGH);
  delay(100);
  digitalWrite(yellowpin,LOW);
  digitalWrite(ledPin,LOW);
   delay(100);
}
else if(pitch>0)
{
  noTone(8);
  digitalWrite(yellowpin,LOW);
    digitalWrite(ledPin,LOW);
}
//tone(8,pitch,20);
//delay(10);
Serial.print("pitch: ");
Serial.println(pitch);
}
