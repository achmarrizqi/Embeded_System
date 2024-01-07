# PWM 1: Example
Program pertama akan digunakan untuk membuat efek fade pada LED menggunakan PWM.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * LED               ==> 3 buah
      * Resistor 220 Ohm  ==> 3 buah

2. Rangkaian

      ![image](https://github.com/alfan459/Embedded-System/assets/54757609/8792b94b-a270-4b61-8a92-8e72fc0594f9)

3. Program

      ![beautify-picture (8)](https://github.com/JustBadrun/Embeded_System/assets/128286595/bcb98cf4-c580-403a-a8c0-b6784aa31bb3)

4. Flowchart

      ![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/513e634c-38f5-4634-ab52-a57a986a241d)

5. Hasil dan Pembahasan

      ![PWM 1](https://github.com/alfan459/Embedded-System/assets/54757609/2e3cddb3-534b-4b23-aad6-f672326ef669)
      
      Kode tersebut adalah program untuk mengendalikan intensitas cahaya dari sebuah LED menggunakan modul PWM (Pulse Width Modulation) pada ESP32. Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

   * Inisialisasi PIN dan Pengaturan PWM:
   ```cpp
   const int ledPin = 16;            // LED terhubung ke pin GPIO16

   // Mengatur pengaturan PWM
   const int freq = 5000;
   const int ledChannel = 0;         // PWM Channel
   const int resolution = 8;         // Resolution bit
   ```

   Kode ini menetapkan pin yang terhubung ke LED (GPIO16) dan mengatur parameter PWM seperti frekuensi (`freq`), channel (`ledChannel`), dan resolusi (`resolution`).

   * Setup:
   ```cpp
   void setup() {
     // Mengkonfigurasi PWM LED
     ledcSetup(ledChannel, freq, resolution);

     // Menghubungkan channel ke GPIO agar bisa dikendalikan
     ledcAttachPin(ledPin, ledChannel);
     pinMode(5, OUTPUT);
     digitalWrite(5, LOW);
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, konfigurasi PWM untuk LED diatur menggunakan `ledcSetup()`, dan channel PWM dihubungkan ke pin GPIO menggunakan `ledcAttachPin()`. Pin GPIO 5 juga diatur sebagai OUTPUT dan dipastikan dalam keadaan LOW.

   * Loop Utama:
   ```cpp
   void loop() {
     // Meningkatkan cahaya LED
     for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
       // Mengatur keterangan cahaya LED dengan PWM
       ledcWrite(ledChannel, dutyCycle);
       delay(15);
     }
     // Mengurangi cahaya LED
     for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
       // Mengatur keterangan cahaya LED dengan PWM
       ledcWrite(ledChannel, dutyCycle);
       delay(15);
     }
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, intensitas cahaya LED secara perlahan ditingkatkan dari nilai duty cycle 0 hingga 255 menggunakan loop pertama. Setelah mencapai nilai maksimum, intensitas cahaya kemudian dikurangi dari 255 hingga 0 menggunakan loop kedua. Delay 15ms diatur antara setiap perubahan nilai duty cycle untuk memberikan efek perubahan intensitas cahaya yang halus.

Dengan menggunakan modul PWM, program ini dapat menghasilkan efek fading atau perubahan intensitas cahaya secara gradual pada LED yang terhubung ke pin GPIO16.
<br></br>

# PWM 2: Pengendalian 3 LED dengan Satu Channel PWM
Program pertama akan digunakan untuk membuat efek fade pada LED menggunakan PWM.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * LED               ==> 3 buah
      * Resistor 220 Ohm  ==> 3 buah

2. Rangkaian

      ![image](https://github.com/alfan459/Embedded-System/assets/54757609/8792b94b-a270-4b61-8a92-8e72fc0594f9)

3. Program

      ![beautify-picture (9)](https://github.com/JustBadrun/Embeded_System/assets/128286595/d2a64b2b-581d-4092-b916-43f9267e8296)

4. Flowchart

      ![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/5170fdd7-efc4-4336-8f00-75edc6b9ff50)


5. Hasil dan Pembahasan

      ![PWM 2](https://github.com/alfan459/Embedded-System/assets/54757609/68196d0b-b263-49db-af58-069f76adcf67)
      
      Kode tersebut adalah program untuk mengendalikan intensitas cahaya dari tiga buah LED menggunakan modul PWM pada ESP32. Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

   * Inisialisasi PIN dan Pengaturan PWM:
   ```cpp
   const int ledPin = 16;   // LED1 terhubung ke pin GPIO16
   const int ledPin2 = 17;  // LED2 terhubung ke pin GPIO17
   const int ledPin3 = 5;   // LED3 terhubung ke pin GPIO5

   // Mengatur pengaturan PWM
   const int freq = 5000;
   const int ledChannel = 0;  // PWM Channel
   const int resolution = 8;  // Resolution bit
   ```

   Kode ini menetapkan tiga pin yang terhubung ke LED (GPIO16, GPIO17, dan GPIO5) dan mengatur parameter PWM seperti frekuensi (`freq`), channel (`ledChannel`), dan resolusi (`resolution`).

   * Setup:
   ```cpp
   void setup() {
     // Mengkonfigurasi PWM LED
     ledcSetup(ledChannel, freq, resolution);

     // Menghubungkan channel ke GPIO agar bisa dikendalikan
     ledcAttachPin(ledPin, ledChannel);
     ledcAttachPin(ledPin2, ledChannel);
     ledcAttachPin(ledPin3, ledChannel);
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, konfigurasi PWM untuk ketiga LED diatur menggunakan `ledcSetup()`, dan channel PWM dihubungkan ke pin GPIO menggunakan `ledcAttachPin()`.

   * Loop Utama:
   ```cpp
   void loop() {
     // Meningkatkan cahaya LED
     for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
       // Mengatur keterangan cahaya LED dengan PWM
       ledcWrite(ledChannel, dutyCycle);
       delay(15);
     }
     // Mengurangi cahaya LED
     for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
       // Mengatur keterangan cahaya LED dengan PWM
       ledcWrite(ledChannel, dutyCycle);
       delay(15);
     }
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, intensitas cahaya ketiga LED secara perlahan ditingkatkan dari nilai duty cycle 0 hingga 255 menggunakan loop pertama. Setelah mencapai nilai maksimum, intensitas cahaya kemudian dikurangi dari 255 hingga 0 menggunakan loop kedua. Delay 15ms diatur antara setiap perubahan nilai duty cycle untuk memberikan efek perubahan intensitas cahaya yang halus.

Dengan menggunakan modul PWM, program ini dapat menghasilkan efek fading atau perubahan intensitas cahaya secara gradual pada ketiga LED yang terhubung ke pin GPIO16, GPIO17, dan GPIO5.
<br></br>
