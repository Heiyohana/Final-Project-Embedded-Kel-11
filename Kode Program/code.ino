int limitswitch = 8;
#include <Servo.h> 
Servo myservo;
int trigPin = A2; 
int echoPin = A1; 
long duration, cm, meter; 
void setup() { 
Serial.begin(9600); 
 pinMode(limitswitch,INPUT);
 myservo.attach(5); 
 pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() { 
 digitalWrite(trigPin, LOW);
delayMicroseconds(5); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH); 
cm = (duration/2) / 29.1;
meter = (duration/2) / 100;
delay(500);
 int val = digitalRead(limitswitch);
 if( val == 1 ){ 
 myservo.write(90); 
 delay(300); 
 }
 else {
 myservo.write(0); 
 delay(300);  
 }
 if(cm<=8){
myservo.write(180);
delay(300);
}
 delay(300);
}
