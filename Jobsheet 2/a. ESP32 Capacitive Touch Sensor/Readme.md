# ESP32 TOUCH 1: Example
Program pertama akan digunakan untuk menampilkan pembacaan sensor touch ESP32.

## Alat dan Bahan
1. ESP32             ==> 1 buah

## Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/f172e71d-7663-476e-b929-b32ce02d00b5)

## Program

![beautify-picture (3)](https://github.com/JustBadrun/Embeded_System/assets/128286595/f660db38-9ba6-442f-8be5-060c76f1175c)

## Flowchart

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/94fcdd67-e4f3-4228-8b80-c2f623d2e039)

## Hasil dan Pembahasan

https://github.com/alfan459/Embedded-System/assets/54757609/caead734-0d30-4f79-be89-72f7cb674c8f

Program di atas merupakan program sederhana untuk menguji sensor sentuh pada ESP32. Berikut adalah penjelasan singkat mengenai kode tersebut:

1. **Setup:**
   ```cpp
   void setup() {
     Serial.begin(115200);     // Inisialisasi komunikasi serial dengan baudrate 115200
     delay(1000);              // Jeda awal selama 1000 milidetik (1 detik)
     Serial.println("ESP32 Touch Test");  // Menampilkan pesan di Serial Monitor
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, komunikasi serial diatur dengan baudrate 115200, kemudian terdapat jeda awal selama 1000 milidetik, dan pesan "ESP32 Touch Test" ditampilkan di Serial Monitor.

2. **Loop Utama:**
   ```cpp
   void loop() {
     Serial.println(touchRead(4));  // Membaca dan menampilkan nilai sentuhan pada pin Touch 0 (GPIO 4) di Serial Monitor
     delay(1000);  // Jeda selama 1000 milidetik (1 detik)
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sentuhan pada pin Touch 0 (GPIO 4) dibaca menggunakan fungsi `touchRead(4)`. Nilai tersebut kemudian ditampilkan di Serial Monitor menggunakan `Serial.println()`. Setelah itu, program menunggu selama 1000 milidetik sebelum membaca kembali nilai sentuhan.

Program ini sederhana dan digunakan untuk memantau nilai sentuhan pada pin Touch 0 (GPIO 4) dari ESP32 dan menampilkannya di Serial Monitor setiap detik sekali. Nilai yang ditampilkan akan berupa angka analog, dan nilai yang lebih tinggi biasanya menunjukkan sentuhan yang lebih kuat.
<br></br>

# ESP32 TOUCH 2: Menyalakan LED Lewat Sensor Touch
Program kedua digunakan untuk mengatur kondisi LED menyala atau tidak melalui sensor touch ESP 32.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah

## Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1eaff866-7a60-478d-a3d5-e373569772c9)

## Program

![beautify-picture (4)](https://github.com/JustBadrun/Embeded_System/assets/128286595/eb0505a6-05da-4873-93c8-4f8a29b6683d)

## Flowchart

![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/96206f0e-a708-43ae-a224-9af7bbf7c080)

## Hasil dan Pembahasan

![touch2](https://github.com/alfan459/Embedded-System/assets/54757609/9e2e53b8-c511-4ed6-9958-ffcae10c2c71)

Program di atas merupakan contoh penggunaan sensor sentuh pada ESP32 untuk mengontrol LED. Berikut adalah penjelasan singkat mengenai kode tersebut:

1. **Setup:**
   ```cpp
   void setup(){
     Serial.begin(115200);        // Inisialisasi komunikasi serial dengan baudrate 115200
     delay(1000);                 // Jeda awal selama 1000 milidetik (1 detik)
     pinMode (ledPin, OUTPUT);    // Inisialisasi LED sebagai output
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, komunikasi serial diatur dengan baudrate 115200, terdapat jeda awal selama 1000 milidetik, dan pin LED (GPIO 16) diatur sebagai output.

2. **Loop Utama:**
   ```cpp
   void loop(){
     touchValue = touchRead(touchPin);    // Membaca nilai sentuhan dari pin Touch
     Serial.print(touchValue);            // Menampilkan nilai sentuhan ke Serial Monitor
     
     // Jika nilai sentuhan kurang dari nilai ambang batas (threshold), maka lampu akan berkedip
     if(touchValue < threshold){
       // Menyalakan LED
       digitalWrite(ledPin, HIGH);
       delay(1000);
       // Mematikan LED
       digitalWrite(ledPin, LOW);
       delay(1000);
       Serial.println(" - LED Blink");
     }
     // Jika tidak, matikan lampu
     else{
       // Mematikan LED
       digitalWrite(ledPin, LOW);
       Serial.println(" - LED off");
     }
     delay(500);  // Jeda selama 500 milidetik sebelum membaca nilai sentuhan lagi
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sentuhan dari pin Touch (GPIO 4) dibaca menggunakan `touchRead(touchPin)`. Nilai tersebut kemudian ditampilkan di Serial Monitor menggunakan `Serial.print()`. Jika nilai sentuhan kurang dari nilai threshold (20), maka LED (GPIO 16) akan berkedip dengan interval 1 detik, dan statusnya ditampilkan di Serial Monitor. Jika nilai sentuhan tidak mencapai threshold, LED dimatikan, dan statusnya juga ditampilkan di Serial Monitor. Setelah itu, terdapat jeda selama 500 milidetik sebelum membaca kembali nilai sentuhan.
   
<br></br>

# ESP32 TOUCH 3: LED Blink & Touchsensor
Program ini digunakan untuk menyalakan LED secara blink ketika sensor touch disentuh.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. Resistor 220 ohm  ==> 1 buah
3. LED               ==> 1 buah

## Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1eaff866-7a60-478d-a3d5-e373569772c9)

## Program

![beautify-picture (5)](https://github.com/JustBadrun/Embeded_System/assets/128286595/7f2c4e01-25c1-45f0-8686-d2d72c358add)

## Flowchart

![Flowchart 3](https://github.com/alfan459/Embedded-System/assets/54757609/6a8936ef-da54-4475-91cd-f63e896309a0)

## Hasil dan Pembahasan

![touch3](https://github.com/alfan459/Embedded-System/assets/54757609/f58b84ff-c28f-49a2-9c2a-d803b31ae20f)

Program di atas menggunakan sensor sentuh pada pin GPIO4 dan mengontrol LED pada pin GPIO16. Berikut adalah penjelasan singkat mengenai kode tersebut:

1. **Setup:**
   ```cpp
   void setup(){
     Serial.begin(115200);        // Inisialisasi komunikasi serial dengan baudrate 115200
     delay(1000);                 // Jeda awal selama 1000 milidetik (1 detik)
     pinMode (ledPin, OUTPUT);    // Inisialisasi LED sebagai output
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, komunikasi serial diatur dengan baudrate 115200, terdapat jeda awal selama 1000 milidetik, dan pin LED (GPIO 16) diatur sebagai output.

2. **Loop Utama:**
   ```cpp
   void loop(){
     touchValue = touchRead(touchPin);    // Membaca nilai sentuhan dari pin Touch (GPIO4)
     Serial.print(touchValue);            // Menampilkan nilai sentuhan ke Serial Monitor
     
     // Jika nilai sentuhan kurang dari nilai ambang batas (threshold), maka lampu akan berkedip
     if(touchValue < threshold){
       // Menyalakan LED
       digitalWrite(ledPin, HIGH);
       delay(1000);
       // Mematikan LED
       digitalWrite(ledPin, LOW);
       delay(1000);
       Serial.println(" - LED Blink");
     }
     // Jika tidak, matikan lampu
     else{
       // Mematikan LED
       digitalWrite(ledPin, LOW);
       Serial.println(" - LED off");
     }
     delay(500);  // Jeda selama 500 milidetik sebelum membaca nilai sentuhan lagi
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sentuhan dari pin Touch (GPIO 4) dibaca menggunakan `touchRead(touchPin)`. Nilai tersebut kemudian ditampilkan di Serial Monitor menggunakan `Serial.print()`. Jika nilai sentuhan kurang dari nilai threshold (20), maka LED (GPIO 16) akan berkedip dengan interval 1 detik, dan statusnya ditampilkan di Serial Monitor. Jika nilai sentuhan tidak mencapai threshold, LED dimatikan, dan statusnya juga ditampilkan di Serial Monitor. Setelah itu, terdapat jeda selama 500 milidetik sebelum membaca kembali nilai sentuhan.
<br></br>

# ESP32 TOUCH 4: Touchsensor Count
Program ini digunakan untuk menampilkan nilai yang terus bertambah pada serial monitor ketika touchsensor ditekan.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 ohm  ==> 1 buah

## Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1eaff866-7a60-478d-a3d5-e373569772c9)

## Program

![beautify-picture (6)](https://github.com/JustBadrun/Embeded_System/assets/128286595/801883ae-f591-4018-ab52-616140ef6e8d)

## Flowchart

![Flowchart 4](https://github.com/alfan459/Embedded-System/assets/54757609/d12c3870-5c53-40cd-9eef-bdd5f421809b)

## Hasil dan Pembahasan

https://github.com/alfan459/Embedded-System/assets/54757609/505c5c47-1b4f-40c5-8997-02c481a8cb3e

Program di atas menggunakan sensor sentuh pada pin GPIO4 dan mengontrol LED pada pin GPIO2. Berikut adalah penjelasan singkat mengenai kode tersebut:

1. **Setup:**
   ```cpp
   void setup() {
     Serial.begin(115200);   // Inisialisasi komunikasi serial dengan baudrate 115200
     pinMode(ledPin, OUTPUT); // Inisialisasi pin LED (GPIO2) sebagai output
     pinMode(touchPin, INPUT); // Inisialisasi pin sensor sentuh (GPIO4) sebagai input
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, komunikasi serial diatur dengan baudrate 115200, pin LED (GPIO2) diatur sebagai output, dan pin sensor sentuh (GPIO4) diatur sebagai input.

2. **Loop Utama:**
   ```cpp
   void loop() {
     if (digitalRead(touchPin) == HIGH) {
       // Jika sensor sentuh disentuh, tambahkan 1 ke touchCount
       touchCount++;
       
       // Hidupkan LED
       digitalWrite(ledPin, HIGH);
   
       // Tampilkan touchCount di Serial Monitor
       Serial.print("Sentuhan ke-");
       Serial.println(touchCount);
       
       // Tunggu sebentar untuk menghindari deteksi berulang
       delay(500);
     } else {
       // Matikan LED jika sensor tidak disentuh
       digitalWrite(ledPin, LOW);
     }
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, kondisi dari sensor sentuh (GPIO4) dibaca menggunakan `digitalRead(touchPin)`. Jika kondisi tersebut adalah `HIGH` (sensor sentuh disentuh), maka `touchCount` akan ditambah 1, LED (GPIO2) akan dinyalakan, dan informasi mengenai jumlah sentuhan akan ditampilkan di Serial Monitor. Setelah itu, terdapat jeda selama 500 milidetik untuk menghindari deteksi berulang. Jika kondisi sensor sentuh adalah `LOW` (tidak disentuh), LED dimatikan.
<br></br>

# ESP32 TOUCH 5: Touchsensor & Running LED
Program ini digunakan untuk menyalakan LED secara running dari kiri ke kanan ketika touchsensor ditekan.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. LED               ==> 3 buah
3. Resistor 220 ohm  ==> 3 buah

## Rangkaian

![rangkaian5](https://github.com/alfan459/Embedded-System/assets/54757609/61b78942-b317-4169-bea8-0e518f47d3df)

## Program

![beautify-picture (7)](https://github.com/JustBadrun/Embeded_System/assets/128286595/a4929644-317e-4d0e-876f-66118dca75d0)

## Flowchart

![Flowchart 4](https://github.com/alfan459/Embedded-System/assets/54757609/d12c3870-5c53-40cd-9eef-bdd5f421809b)

## Hasil dan Pembahasan

![touch5](https://github.com/alfan459/Embedded-System/assets/54757609/faf4252e-1251-406a-8cae-952e32aa6b2e)

Program di atas menggunakan sensor sentuh pada pin GPIO4 dan mengontrol tiga buah LED pada pin GPIO16, GPIO17, dan GPIO18. Berikut adalah penjelasan singkat mengenai kode tersebut:

1. **Setup:**
   ```cpp
   void setup() {
     Serial.begin(115200);   // Inisialisasi komunikasi serial dengan baudrate 115200
     delay(1000);            // Delay awal
     // Inisialisasi LED sebagai output
     pinMode(led1, OUTPUT);
     pinMode(led2, OUTPUT);
     pinMode(led3, OUTPUT);
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, komunikasi serial diatur dengan baudrate 115200, dan tiga LED (GPIO16, GPIO17, dan GPIO18) diatur sebagai output.

2. **Loop Utama:**
   ```cpp
   void loop() {
     touchValue = touchRead(touchPin);    // Membaca nilai sensor sentuh
     Serial.print(touchValue);            // Menampilkan nilai sensor sentuh ke Serial Monitor

     // Jika nilai sensor sentuh lebih kecil dari nilai treshold, maka lampu akan blink
     if(touchValue < threshold){
       // Mengatur pola blink untuk tiga LED
       // ...
     }
     // Jika tidak, matikan lampu
     else{
       // Mematikan semua LED
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
     }
     delay(500); // Delay untuk menghindari deteksi berulang
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sensor sentuh (GPIO4) dibaca menggunakan `touchRead(touchPin)`. Jika nilai tersebut lebih kecil dari nilai treshold, maka akan dijalankan pola blink untuk tiga LED. Jika tidak, semua LED dimatikan. Terdapat delay sebesar 500 milidetik untuk menghindari deteksi berulang. Pola blink pada LED1, LED2, dan LED3 dapat diatur sesuai kebutuhan di dalam bagian yang ditandai sebagai `// Mengatur pola blink untuk tiga LED`.
<br></br>


