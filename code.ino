#include <Servo.h> //Library Servo

Servo myservo; //Membuat variabel servo untuk dikendalikan bernama myservo

#define trig 5 //Pin Trigger dari sensor Ultrasonic 
#define echo 6 //Pin Echo dari sensor Ultrasonic 

int pos = 0; //Deklarasi variabel untuk posisi sudut awal micro servo

int sensor=9; //Deklarasi variabel sensor capasitif proximity pada pin 9
int led=8; //Deklarasi variabel aktuator led pada pin 8
int sampah; //Deklarasi variabel sampah untuk menyimpan kondisi masukan dari sensor capasitif proximity

//Mengatur dan menyiapkan semua variable yang digunakan
void setup(){
  myservo.attach(10); //Deklarasi variabel myservo pada pin 10
  Serial.begin(9600); //Mengatur kecepatan dan penerimaan data melalui serial port sebesar 9600 bit per detik
  pinMode(sensor,INPUT); //Mengatur sensor kapasitif menjadi inputan 
  pinMode(led,OUTPUT); //Mengatur led menjadi output untuk menyalakan lampu LED
  pinMode(trig, OUTPUT); //Mengatur trig menjadi output
  pinMode(echo, INPUT); //Deklarasi pin echo menjadi input
}

//Mengeksekusi dan menjalankan program
void loop(){
  long durasi, jarak; //Variabel durasi dan jarak
  sampah = digitalRead(sensor); //Membaca nilai dari variabel sensor kapasistif dan disimpan pada variabel sampah

  delay(1000); //Delay (Menunggu 1 detik)
  Serial.println(""); //Mencetak tulisan ke serial monitor
  Serial.println("FINAL PROJECT BY GROUP NUMBER 11"); //Mencetak tulisan ke serial monitor
  
  digitalWrite(trig,LOW); //Mengatur pin trig menjadi off
  delay(10); //Memberikan waktu pin trig untuk off selama 10 detik
  digitalWrite(trig,HIGH); //Mengatur pin trig menjadi on
  delay(10); //Memberikan waktu pin trig untuk on selama 10 detik untuk memberikan gelombang ultrasonik
  digitalWrite(trig,LOW); //Mengatur pin trig menjadi off kembali
  //delayMircoseconds(10); //Memberikan waktu jeda pada pin trig supaya nantinya berguna untuk pin echo menerima gelombang yang dipancarkan oleh pin trigger
 
  durasi = pulseIn(echo,HIGH); 
 //Membaca perintah pulseIn yang digunakan untuk menunggu rentang waktu pin echo dari LOW ke HIGH, sehingga Arduino dapat mengetahui waktu atau durasi perjalanan dari trigger ke echo karena pantulan benda.
  jarak = (durasi/2) / 29.1; //Perhitungan untuk pembacaan jarak, durasi disini dibagi 2 dikarenakan waktunya tersebut merupakan waktu bolak-balik (sensor - benda - sensor)
  
  //Kondisi saat sampah sudah diletakkan 
  if (jarak >0 && jarak < 15){ //Kondisi saat benda diletakkan dan berjarak lebih dari 0 dan kurang dari 15
    //Mencetak jarak sampahnya
    Serial.print("Jarak : "); //Mencetak tulisan ke serial monitor
    Serial.print(jarak); //Mencetak nilai dari variabel jarak berdasarkan perhitungan yang dilakukan sebelumnya.
    Serial.println(" cm"); //Mencetak tulisan ke serial monitor
    
    //Mengkategorikan jenis sampah
    Serial.print("Sampah Terdeteksi : "); //Mencetak tulisan ke serial monitor
    
    //Kondisi saat sampah Organik (sisa sayur, daun, dll)
    if(sampah == 1){ //Kondisi saat sampah sudah diletakkan dan merupakan sampah organik.
      digitalWrite (led, LOW); //Memerintahkan Lampu LED untuk menyala
      Serial.println("Organik"); //Mencetak tulisan ke serial monitor
      //Jatuh ke kotak kanan
      for(pos = 180; pos < 0; pos+= 1) // perulangan untuk posisi 0 sampai 180 derajat
      { // step setiap 1 derajat
          myservo.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos
          delay(15); //Menunggu 15 milidetik
      }
    } 
    //Kondisi saat sampah Anorganik (kaleng, gantungan kunci)
    else if(sampah == 0){
      digitalWrite (led, HIGH); //Memerintahkan Lampu LED untuk menyala
      Serial.println("Anorganik"); //Mencetak tulisan ke serial monitor
      //Jatuh ke kotak kiri
      for(pos = 0; pos < 180; pos+= 1) // perulangan untuk posisi 0 sampai 180 derajat
      { // step setiap 1 derajat
          myservo.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos
          delay(15); //Menunggu 15 milidetik
      }
    }

  //kondisi saat sampah tidak diletakkan
  }else {
    myservo.write(pos); //Mencetak nilai dari variabel pos
    digitalWrite(led, HIGH); //Menyalakan Lampu LED
    delay (1000); //Menunggu 1 detik
    digitalWrite(led, LOW); //Mematikan Lampu LED
  }
}
delay(300); //Menunggu selama 300 milidetik
}
 delay(300); //Menunggu selama 300 milidetik
}
