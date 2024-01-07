# ESP32 & DHT11 1: Example
Program pertama akan digunakan untuk mencoba sensor DHT11.

## Alat dan Bahan
1. ESP32            ==> 1 buah
2. Resistor 10K ohm ==> 1 buah
3. DHT11            ==> 1 buah  

## Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1fe265a4-125d-48cc-b898-fea30cf33965)

## Program

![beautify-picture (8)](https://github.com/JustBadrun/Embeded_System/assets/128286595/62223e36-88ff-48c2-b696-9ba62e9e2e68)

## Flowchart

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/d7b54174-694b-43ee-a919-b75cbd598c0f)

## Hasil dan Pembahasan

https://github.com/alfan459/Embedded-System/assets/54757609/832715cd-2ba7-4708-9520-d3906ddc5ae0

Program di atas menggunakan sensor suhu dan kelembapan DHT11 untuk mengukur kondisi lingkungan. Berikut adalah penjelasan singkat mengenai kode tersebut:

1. **Inklusi Library dan Pendefinisian Konstanta:**
   ```cpp
   #include "DHT.h"

   #define DHTPIN 4           // Digital pin terhubung ke DHT sensor

   // Uncomment type yang tidak digunakan
   #define DHTTYPE DHT11      // DHT 11
   // #define DHTTYPE DHT22    // DHT 22  (AM2302), AM2321
   // #define DHTTYPE DHT21    // DHT 21 (AM2301)
   DHT dht(DHTPIN, DHTTYPE);
   ```

   Program menggunakan library DHT untuk mengakses sensor DHT11. Konstanta `DHTPIN` menyimpan nomor pin digital yang terhubung ke sensor.

2. **Setup:**
   ```cpp
   void setup() {
     Serial.begin(9600);    // Komunikasi serial diatur ke baudrate 9600
     Serial.println(F("DHT11 Embedded System Test!"));
     dht.begin();           // Memulai komunikasi dengan sensor DHT
   }
   ```

   Pada fungsi `setup()`, komunikasi serial diatur dengan baudrate 9600. Selanjutnya, fungsi `begin()` dari objek `dht` dipanggil untuk memulai komunikasi dengan sensor DHT.

3. **Loop Utama:**
   ```cpp
   void loop() {
     // Jeda antar pengukuran.
     delay(2000);

     // Pembacaan suhu atau kelembapan sekitar 250 milliseconds!
     float h = dht.readHumidity();    // Membaca kelembapan
     float t = dht.readTemperature(); // Membaca suhu dalam Celsius
     float f = dht.readTemperature(true); // Membaca suhu dalam Fahrenheit
     // Cek jika ada pembacaan yang salah atau gagal agar bisa memulai ulang
     if (isnan(h) || isnan(t) || isnan(f)) {
       Serial.println(F("Failed to read from DHT sensor!"));
       return;
     }

     // Menghitung heat index dalam Fahrenheit (default)
     float hif = dht.computeHeatIndex(f, h);
     // Menghitung heat index dalam Celsius
     float hic = dht.computeHeatIndex(t, h, false);
     // Menampilkan hasil pembacaan ke Serial Monitor
     Serial.print(F("Humidity: "));
     Serial.print(h);
     Serial.print(F("%  Temperature: "));
     Serial.print(t);
     Serial.print(F("°C "));
     Serial.print(f);
     Serial.print(F("°F  Heat index: "));
     Serial.print(hic);
     Serial.print(F("°C "));
     Serial.print(hif);
     Serial.println(F("°F"));
   }
   ```

   Loop utama program ini melakukan pengukuran suhu dan kelembapan setiap 2 detik sekali. Hasil pembacaan kemudian ditampilkan ke Serial Monitor. Jika pembacaan gagal atau ada kesalahan, pesan kesalahan akan dicetak di Serial Monitor.
<br></br>

# ESP32 & DHT11 2: Controlling LED & Buzzer
Program kedua digunakan untuk mengatur kondisi LED dan buzzer menyala atau tidak melalui sensor DHT11.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. DHT11             ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10K ohm  ==> 1 buah 

## Rangkaian

![Rangkaian](https://github.com/alfan459/Embedded-System/assets/54757609/404322eb-617c-4736-974d-c1ec60d3c022)

## Program

![beautify-picture (9)](https://github.com/JustBadrun/Embeded_System/assets/128286595/80d27021-a456-4af8-bbc4-ca09fa457a9e)

## Flowchart

![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/52f6d721-8505-4c49-b68a-bbe060b83016)

## Hasil dan Pembahasan**

https://github.com/alfan459/Embedded-System/assets/54757609/2e9c38bc-0893-4240-98a9-303b0f99527e

Program di atas menggabungkan penggunaan sensor suhu dan kelembapan DHT11 dengan kontrol LED dan buzzer berdasarkan nilai suhu yang terukur. Berikut adalah penjelasan singkat mengenai kode tersebut:

1. **Inklusi Library dan Pendefinisian Konstanta:**
   ```cpp
   // Menambahkan library DHT
   #include "DHT.h"

   #define DHTPIN 4           // Digital pin terhubung ke DHT sensor

   // Uncomment type yang tidak digunakan
   #define DHTTYPE DHT11      // DHT 11
   // #define DHTTYPE DHT22    // DHT 22  (AM2302), AM2321
   // #define DHTTYPE DHT21    // DHT 21 (AM2301)
   DHT dht(DHTPIN, DHTTYPE);

   const int led1 = 16;       // LED1 dihubungkan pada GPIO16
   const int led2 = 18;       // LED2 dihubungkan pada GPIO18
   const int led3 = 19;       // LED3 dihubungkan pada GPIO19
   const int buzzer = 10;     // Buzzer dihubungkan pada GPIO10
   ```

   Program menggunakan library DHT untuk mengakses sensor DHT11. Konstanta `DHTPIN` menyimpan nomor pin digital yang terhubung ke sensor. Selain itu, juga terdapat definisi pin untuk LED (led1, led2, led3) dan buzzer.

2. **Setup:**
   ```cpp
   void setup() {
     Serial.begin(9600);    // Komunikasi serial diatur ke baudrate 9600
     Serial.println(F("DHT11 Embedded System Test!"));
     dht.begin();           // Memulai komunikasi dengan sensor DHT

     // Inisialisasi LED dan Buzzer sebagai output:
     pinMode(led1, OUTPUT);
     pinMode(led2, OUTPUT);
     pinMode(led3, OUTPUT);
     pinMode(buzzer, OUTPUT);
   }
   ```

   Pada fungsi `setup()`, komunikasi serial diatur dengan baudrate 9600. Selanjutnya, fungsi `begin()` dari objek `dht` dipanggil untuk memulai komunikasi dengan sensor DHT. Pin LED dan buzzer diinisialisasi sebagai output.

3. **Loop Utama:**
   ```cpp
   void loop() {
     // Jeda antar pengukuran.
     delay(2000);
     
     // Pembacaan suhu atau kelembapan sekitar 250 milliseconds!
     float h = dht.readHumidity();    // Membaca kelembapan
     float t = dht.readTemperature(); // Membaca suhu dalam Celsius
     float f = dht.readTemperature(true); // Membaca suhu dalam Fahrenheit
     // Cek jika ada pembacaan yang salah atau gagal agar bisa memulai ulang
     if (isnan(h) || isnan(t) || isnan(f)) {
       Serial.println(F("Failed to read from DHT sensor!"));
       return;
     }

     // Hitung heat index dalam Fahrenheit (default)
     float hif = dht.computeHeatIndex(f, h);
     // Hitung heat index dalam Celsius
     float hic = dht.computeHeatIndex(t, h, false);
     Serial.print(F("Humidity: "));
     Serial.print(h);
     Serial.print(F("%  Temperature: "));
     Serial.print(t);
     Serial.print(F("°C "));
     Serial.print(f);
     Serial.print(F("°F  Heat index: "));
     Serial.print(hic);
     Serial.print(F("°C "));
     Serial.print(hif);
     Serial.println(F("°F"));

     // Kontrol LED dan Buzzer berdasarkan suhu
     if (t < 30.00 || t == 30.00) {
       digitalWrite(led1, HIGH);
       digitalWrite(buzzer, HIGH);
       delay(1000);
       digitalWrite(buzzer, LOW);
       delay(1000);
     } else {
       digitalWrite(buzzer, LOW);
       // Turn LED on
       digitalWrite(led1, HIGH);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
       delay(800);
       // ... (pattern LED lainnya)
     }
   }
   ```

   Loop utama program ini melakukan pengukuran suhu dan kelembapan setiap 2 detik sekali. Hasil pembacaan kemudian ditampilkan ke Serial Monitor. Kontrol LED dan buzzer dilakukan berdasarkan nilai suhu yang terukur. Jika suhu berada di bawah atau sama dengan 30 derajat, LED1 akan menyala dan buzzer akan berbunyi selama 1 detik. Jika tidak, akan dilakukan kontrol LED dengan pola tertentu (contoh di atas menunjukkan pola LED yang berbeda).
<br></br>
