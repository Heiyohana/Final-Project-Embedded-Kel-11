#include <Servo.h> 

Servo myservo; 

#define trig 5 
#define echo 6 

int pos = 0; 

int sensor=9; 
int led=8; 
int sampah; 

void setup(){
  myservo.attach(10);
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT); 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
}

void loop(){
  long durasi, jarak; 
  sampah = digitalRead(sensor); 

  delay(1000); 
  Serial.println(""); 
  Serial.println("FINAL PROJECT BY GROUP NUMBER 11"); 
  
  digitalWrite(trig,LOW); 
  delay(10); 
  digitalWrite(trig,HIGH); 
  delay(10); 
  digitalWrite(trig,LOW); 
  //delayMircoseconds(10); 
 
  durasi = pulseIn(echo,HIGH); 
  jarak = (durasi/2) / 29.1; 
  
 
  if (jarak >0 && jarak < 15){ 
    Serial.print("Jarak : "); 
    Serial.print(jarak); 
    Serial.println(" cm"); 
    
    Serial.print("Sampah Terdeteksi : "); 
    
    if(sampah == 1){ 
      digitalWrite (led, LOW); 
      Serial.println("Organik"); 
      
      for(pos = 180; pos < 0; pos+= 1) 
      { 
          myservo.write(pos); 
          delay(15); 
      }
    } 
    else if(sampah == 0){
      digitalWrite (led, HIGH); 
      Serial.println("Anorganik"); 
      
      for(pos = 0; pos < 180; pos+= 1) 
      { 
          myservo.write(pos); 
          delay(15); 
      }
    }
    
  }else {
    myservo.write(pos); 
    digitalWrite(led, HIGH); 
    delay (1000); 
    digitalWrite(led, LOW); 
  }
}
delay(300); 
}
 delay(300); 
}
