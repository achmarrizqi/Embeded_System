# ADC DAC: Example
Program pertama akan digunakan untuk menampilkan pembacaan potensio.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * Potensio 10k Ohm  ==> 1 buah

2. Rangkaian

      ![image](https://github.com/alfan459/Embedded-System/assets/54757609/2c9c037a-9eb1-472a-833c-7137a8311d9a)

3. Program

   ![beautify-picture (10)](https://github.com/JustBadrun/Embeded_System/assets/128286595/8f00432b-14a1-4c9a-abad-2518434a81be)

4. Flowchart

      ![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/fb0bebfc-f73a-4bbc-886b-bc8e87bf75fc)

5. Hasil dan Pembahasan

      ![ADC DAC 1](https://github.com/alfan459/Embedded-System/assets/54757609/67c66308-4865-4563-86f5-7198c5c76a53)

      Program ESP32 di atas membaca nilai analog dari potensiometer yang terhubung ke pin GPIO34 (Analog ADC1_CH6) dan menampilkan nilai tersebut ke Serial Monitor setiap 500 milidetik. Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

   * Inisialisasi PIN dan Variabel:
   ```cpp
   // Potentiometer terhubung ke GPIO34 (Analog ADC1_CH6)
   const int potPin = 34;

   // Variable untuk menyimpan nilai potensiometer
   int potValue = 0;
   ```

   Kode ini menetapkan pin di mana potensiometer terhubung (GPIO34) dan mendeklarasikan variabel `potValue` untuk menyimpan nilai pembacaan analog dari potensiometer.

   * Setup:
   ```cpp
   void setup() {
     Serial.begin(115200);  // Memulai komunikasi serial dengan baudrate 115200
     delay(1000);           // Jeda waktu pertama kali
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, komunikasi serial diatur dengan `Serial.begin(115200)`, dan program memberikan jeda 1000 milidetik (1 detik) menggunakan `delay(1000)` setelah memulai komunikasi serial.

   * Loop Utama:
   ```cpp
   void loop() {
     // Membaca nilai potensiometer
     potValue = analogRead(potPin);
     Serial.println(potValue);  // Menampilkan nilai potensio ke serial monitor
     delay(500);                 // Jeda 500 milidetik (0.5 detik)
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai analog dari potensiometer dibaca menggunakan `analogRead(potPin)`. Nilai tersebut kemudian ditampilkan ke Serial Monitor dengan `Serial.println(potValue)`. Delay 500 milidetik (`delay(500)`) diatur antara setiap pembacaan nilai untuk memberikan interval waktu antar bacaan dan mencegah tampilan nilai yang terlalu cepat di Serial Monitor.

Dengan cara ini, program tersebut memungkinkan pengguna untuk melihat nilai pembacaan analog dari potensiometer pada Serial Monitor secara real-time.


<br></br>

# ADC DAC 2
Program kedua digunakan untuk mengatur cahaya LED menggunakan potensio.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * LED               ==> 1 buah
      * Resistor 220 Ohm  ==> 1 buah
      * Potensio 10k Ohm  ==> 1 buah

2. Rangkaian

      ![rangkaian2](https://github.com/alfan459/Embedded-System/assets/54757609/cae8d5af-9686-42d8-a783-a5bd18d3a090)

3. Program

      ![beautify-picture (11)](https://github.com/JustBadrun/Embeded_System/assets/128286595/882ebd91-8dac-4ba7-9708-fd0286934a8b)

4. Flowchart

      ![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/63129470-c792-4efc-bd5b-05ef3fa92b87)

5. Hasil dan Pembahasan

      ![ADC DAC 2](https://github.com/alfan459/Embedded-System/assets/54757609/7e356dc6-fb4c-4f21-99e2-f1f4b3849738)

      Program ESP32 di atas membaca nilai analog dari potensiometer yang terhubung ke pin GPIO34 dan mengirimkan nilai tersebut ke LED yang terhubung ke pin GPIO5 menggunakan modul PWM (Pulse Width Modulation). Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

   * Inisialisasi PIN dan Variabel:
   ```cpp
   const int analogInPin = 34;     // Pin input analog untuk potensiometer
   const int analogOutPin = 5;     // Pin output analog untuk LED
   
   const int freq = 5000;          // Frekuensi PWM
   const int ledChannel = 0;       // PWM channel
   const int resolution = 8;       // Resolusi PWM (8 bit)
   
   int sensorValue = 0;            // Variabel untuk menyimpan nilai pembacaan potensiometer
   int outputValue = 0;            // Variabel untuk menyimpan nilai keluaran PWM yang dikirim ke LED
   ```

   Kode ini menetapkan pin di mana potensiometer dan LED terhubung, serta mengatur parameter PWM seperti frekuensi, channel, dan resolusi.

   * Setup:
   ```cpp
   void setup() {
     Serial.begin(115200);          // Inisialisasi komunikasi serial dengan baudrate 115200

     // Konfigurasi LED PWM
     ledcSetup(ledChannel, freq, resolution);
     ledcAttachPin(analogOutPin, ledChannel);  // Menghubungkan channel PWM ke pin GPIO
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, komunikasi serial diatur dengan `Serial.begin(115200)`, dan konfigurasi LED PWM dilakukan menggunakan `ledcSetup` dan `ledcAttachPin`.

   * Loop Utama:
   ```cpp
   void loop() {
     sensorValue = analogRead(analogInPin);            // Membaca nilai analog dari potensiometer
     outputValue = map(sensorValue, 0, 4095, 0, 255);  // Menyesuaikan range nilai analog ke range PWM
     analogWrite(analogOutPin, outputValue);           // Mengatur nilai PWM untuk mengendalikan LED

     // Menampilkan hasil bacaan dan keluaran ke Serial Monitor
     Serial.print("sensor = ");
     Serial.print(sensorValue);
     Serial.print("\t output = ");
     Serial.println(outputValue);

     delay(2);  // Menunggu 2 milidetik sebelum pembacaan selanjutnya untuk ADC
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai analog dari potensiometer dibaca menggunakan `analogRead(analogInPin)`. Nilai tersebut kemudian diubah menggunakan `map` untuk sesuaikan dengan rentang PWM (0-255), dan nilai PWM tersebut diatur pada LED menggunakan `analogWrite(analogOutPin, outputValue)`. Selain itu, hasil bacaan dan keluaran ditampilkan di Serial Monitor. Diberikan jeda 2 milidetik (`delay(2)`) sebelum pembacaan berikutnya untuk ADC.

<br></br>


