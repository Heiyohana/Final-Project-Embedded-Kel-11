# Final-Project-Embedded
Code ini digunakan untuk menjalankan alat kami yang bernama "Alat Pemilah Sampah Organik dan Anorganik Otomatis"

# Kelompok 11
Final Project ini beranggotakan 4 orang diantaranya : <br>
1. 119140178 - Hendamia Yohana Sembiring <br>
2. 119140014 - Oktaviani <br> 
3. 119140024 - Viranti <br>
4. 119140054 - Silvia <br>

# Link Video Demo
  Adapun Alat kami dapat terlihat pada link youtube berikut :
    https://youtu.be/fsp5q1aLPjY
  
# Penjelasan Project
    Ini merupakan sebuah projek alat pemilah sampah organik dan anorganik otomatis. Dimana ketika sampah dibuang, maka alat tersebut akan mendeteksi jenis sampah yaitu organik atau anorganik secara otomatis. 
    
    Adapun alat-alat kami ini membutuhkan beberapa komponen diantaranya : 
    1. Sensor Capasitif Proximity 
    2. Sensor HC-SR04 
    3. Micro Servo 
    4. Arduino Uno 
    5. Adaptor 240V 2A
    6. Kabel Jumper
    7. Kabel USB AB
    8. Solder 
    9. Lem Bakar
    10. Timah 
    11. LED 
    12. Baut dan Mur 
    13. Kardus 
    14. Kertas kado (hiasan)

# Cara Kerja 
  Project ini nantinya akan mengkategorikan jenis sampah ke sampah organik dan anorganik. Alat ini nantinya menerima inputan sampah dari user dengan dua kondisi: <br>
  1. Apabila sampah tidak diberikan atau tidak adanya sampah ditempat yang disediakan maka lampu LED akan terus berkedip hingga ada sampah yang diberikan. <br>
  2. Apabila user memberikan sampah maka HC-SR akan mendeteksinya, kemudian menghitung jarak sampah dengan sensor ultrasonik, lalu mengecek jenis sampah dengan sensor capasitif proximity dan menggerakkan micro servo ke arah kanan / kiri sesuai dengan jenis sampah tersebut. <br>
  3. Pada saat sampah di deteksi, lampu LED akan menyala jika sampah tersebut merupakan sampah anorganik. Sedangkan apabila sampah tersebut merupakan jenis sampah organik, maka lampu LED tidak akan menyala. <br>

# Sampel Pengujian
    Ada beberapa sampel sampah yang telah kami uji sebelumnya, antara lain :
    1. Kulit Salak => Organik
    2. Kulit Duku => Organik
    3. Kulit Pisang => Organik
    3. Kaleng Minuman Soda => Anorganik
    4. Gantungan Kunci => Anorganik
    5. Gunting Bekas => Anorganik
    6. Daun Kering => Organik
    7. Alumunium Foil (Bungkus makanan) => Anorganik
  
# Arsitektur Sistem
    Gambar dapat dilihat pada direktori Arsitektur Sistem/1.jpeg
    
# Referensi Project
    1. Akbar, A. (2018). Pembangunan Model Electronic Government Pemerintahan Desa Menuju Smart Desa. Jurnal Teknik dan Informatika, 5(1), 1-5. 
    2. Badawi, A. (2018). Evaluasi Pengaruh Modifikasi Three Pass Protocol Terhadap Transmisi Kunci Enkripsi. 
    3. Cahyawati, Amanda Nur. 2016. Analisis Pemanfaatan Tong Sampah Organik
