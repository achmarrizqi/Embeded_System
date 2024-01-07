# GPIO 1
Program pertama akan digunakan untuk membuat blink dengan interval 100ms, 1 detik, 2 detik, dan 3 detik sekali.

1. Alat dan Bahan
   * ESP32             ==> 1 buah
   * LED               ==> 1 buah
   * Resistor 220 Ohm  ==> 1 buah
   * Resistor 10k Ohm  ==> 1 buah
   * Push button       ==> 1 buah

2. Rangkaian

   ![image](https://github.com/alfan459/Embedded-System/assets/54757609/4850f38f-859e-461b-a830-cd9b53a8e40e)

3. Program

    ![beautify-picture (2)](https://github.com/JustBadrun/Embeded_System/assets/128286595/a4125fea-f606-4737-bbac-69fee09ddece)

4. Flowchart

   ![Flowchart1](https://github.com/alfan459/Embedded-System/assets/54757609/3062ca6a-98dd-441c-8fe5-7019fac6f825)

5. Hasil dan Pembahasan

   https://github.com/JustBadrun/Embeded_System/assets/128286595/a0d04c5c-72f7-4751-bc99-6c04fcde8f4c

   Kode di atas adalah program untuk mengendalikan LED dengan menggunakan ESP32. Berikut adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

  * Inisialisasi PIN dan Setup:
   ```cpp
   const int LedPin = 5;  // Led dihubungkan pada pin GPIO 5

   void setup() {
     pinMode(LedPin, OUTPUT);  // Inisialisasi Led sebagai OUTPUT
   }
   ```
   Kode ini menetapkan bahwa LED akan dihubungkan ke pin GPIO 5 dan menginisialisasi pin tersebut sebagai output di dalam fungsi `setup()`. Fungsi `setup()` dijalankan sekali pada awal program.

  * Loop Utama:
   ```cpp
   void loop() {
     // Nyala 100ms dan mati selama 1 detik
     digitalWrite(LedPin, HIGH);
     delay(100);
     digitalWrite(LedPin, LOW);
     delay(1000);

     // Nyala 1 detik dan mati selama 1 detik
     digitalWrite(LedPin, HIGH);
     delay(1000);
     digitalWrite(LedPin, LOW);
     delay(1000);

     // Nyala 2 detik dan mati selama 1 detik
     digitalWrite(LedPin, HIGH);
     delay(2000);
     digitalWrite(LedPin, LOW);
     delay(1000);

     // Nyala 3 detik dan mati selama 1 detik
     digitalWrite(LedPin, HIGH);
     delay(3000);
     digitalWrite(LedPin, LOW);
     delay(1000);
   }
   ```
   Bagian ini merupakan loop utama program yang akan terus diulang. Setiap iterasi loop, LED akan menyala dan mati dengan pola waktu tertentu. Pola tersebut dijelaskan sebagai berikut:
   - LED menyala selama 100ms dan mati selama 1 detik.
   - LED menyala selama 1 detik dan mati selama 1 detik.
   - LED menyala selama 2 detik dan mati selama 1 detik.
   - LED menyala selama 3 detik dan mati selama 1 detik.

   Pola ini akan terus berulang selama program berjalan di dalam fungsi `loop()`. Fungsi `delay()` digunakan untuk memberikan jeda waktu dalam milidetik antara operasi-operasi tersebut.


<br></br>

# GPIO 2
Program pertama akan digunakan untuk membuat blink 1 detik sekali menggunakan timer milis().

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 1 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 1 buah

2. Rangkaian

    ![image](https://github.com/alfan459/Embedded-System/assets/54757609/4850f38f-859e-461b-a830-cd9b53a8e40e)

3. Program

    ![beautify-picture (3)](https://github.com/JustBadrun/Embeded_System/assets/128286595/d5461284-0e4a-48e6-acf5-4b3b2b505d8d)

4. Flowchart

    ![Flowchart2](https://github.com/alfan459/Embedded-System/assets/54757609/28954bd9-7499-47e5-b546-ec70c1f35ab9)

5. Hasil dan Pembahasan

    ![GPIO 1](https://github.com/alfan459/Embedded-System/assets/54757609/d6d24241-0add-4543-a049-e1a800bf9378)

    Kode di atas merupakan program sederhana untuk mengendalikan LED dengan menggunakan ESP32. Program ini menggunakan konsep *blinking* (nyala-mati secara bergantian) dengan menggunakan fungsi `millis()` untuk mengatur interval waktu. Berikut adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

  * Inisialisasi PIN dan Variabel:
   ```cpp
   const int ledPin = 5;      // LED dihubungkan pada pin GPIO 5
   int ledState = LOW;        // Kondisi yang akan digunakan untuk mengatur LED
   unsigned long previousMillis = 0;  // Waktu terakhir LED dimatikan
   const long interval = 1000;        // Interval untuk blinking (milliseconds)
   ```

   Kode ini menetapkan bahwa LED akan dihubungkan ke pin GPIO 5 dan menginisialisasi variabel `ledState` sebagai `LOW` (mati), `previousMillis` sebagai `0`, dan `interval` sebagai `1000` milidetik (1 detik).

  * Setup:
   ```cpp
   void setup() {
     pinMode(ledPin, OUTPUT);  // Menginisialisasi LED sebagai Output
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, pin LED diinisialisasi sebagai output.

  * Loop Utama:
   ```cpp
   void loop() {
     unsigned long currentMillis = millis();

     if (currentMillis - previousMillis >= interval) {
       previousMillis = currentMillis;  // Menyimpan waktu terakhir LED ngeblink

       // Jika LED dalam keadaan mati, maka nyalakan, dan sebaliknya
       if (ledState == LOW) {
         ledState = HIGH;
       } else {
         ledState = LOW;
       }

       // Atur nyala atau mati LED sesuai dengan nilai variabel ledState
       digitalWrite(ledPin, ledState);
     }
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Setiap iterasi loop, program akan mengecek apakah sudah waktunya untuk mengubah keadaan LED (nyala atau mati) berdasarkan interval yang telah ditentukan. Fungsi `millis()` digunakan untuk menghitung waktu dalam milidetik sejak program dimulai.

     - Jika waktu sekarang (`currentMillis`) dikurangi dengan waktu terakhir LED dimatikan (`previousMillis`) lebih besar atau sama dengan interval yang ditentukan, maka:
       - Waktu terakhir LED dimatikan (`previousMillis`) diupdate.
       - Kondisi LED (`ledState`) diubah (dari mati ke nyala atau sebaliknya).
       - LED diatur sesuai dengan kondisi terkini (`ledState`) menggunakan `digitalWrite()`.
<br></br>

# GPIO 3
Program pertama akan digunakan untuk mengendalikan LED menggunakan push button.

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 1 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 1 buah

2. Rangkaian

    ![image](https://github.com/alfan459/Embedded-System/assets/54757609/4850f38f-859e-461b-a830-cd9b53a8e40e)

3. Program

    ![beautify-picture (5)](https://github.com/JustBadrun/Embeded_System/assets/128286595/9616f336-0fe5-4d59-916b-334411c46dfc)

4. Flowchart

    ![Flowchart3](https://github.com/alfan459/Embedded-System/assets/54757609/e2f8bf50-de43-4b2e-b198-aa04fa0019ef)

5. Hasil dan Pembahasan

    ![GPIO 3](https://github.com/alfan459/Embedded-System/assets/54757609/ea07038b-8f00-4882-8bbf-3fa435e164d7)

    Kode di atas merupakan program sederhana untuk mengendalikan LED menggunakan push button pada ESP32. Berikut adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

  * Inisialisasi PIN dan Variabel:
   ```cpp
   const int buttonPin = 4;  // Pin 4 terhubung ke push button
   const int ledPin = 5;     // Pin 5 terhubung ke LED
   int buttonState = 0;      // Variabel untuk menyimpan keadaan push button
   ```

   Kode ini menetapkan bahwa push button akan dihubungkan ke pin GPIO 4 dan LED dihubungkan ke pin GPIO 5. Variabel `buttonState` akan digunakan untuk menyimpan keadaan (HIGH atau LOW) dari push button.

  * Setup:
   ```cpp
   void setup() {
     Serial.begin(115200);       // Inisialisasi komunikasi serial pada 115200 bps
     pinMode(buttonPin, INPUT);  // Inisialisasi push button sebagai input
     pinMode(ledPin, OUTPUT);    // Inisialisasi LED sebagai output
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, pin untuk push button diinisialisasi sebagai input, dan pin untuk LED diinisialisasi sebagai output. Selain itu, komunikasi serial juga diinisialisasi untuk keperluan debugging.

  * Loop Utama:
   ```cpp
   void loop() {
     buttonState = digitalRead(buttonPin);    // Membaca nilai push button secara digital dan menyimpannya di variabel buttonState
     Serial.println(buttonState);             // Menampilkan nilai buttonState di serial monitor

     // Jika buttonState bernilai HIGH atau push button ditekan, maka akan menyalakan LED
     if (buttonState == HIGH) {
       digitalWrite(ledPin, HIGH);           // Menyalakan LED
     } 
     // Jika tidak ditekan, maka matikan LED
     else {
       digitalWrite(ledPin, LOW);            // Mematikan LED
     }
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, program membaca nilai dari push button menggunakan `digitalRead()` dan menyimpannya di variabel `buttonState`. Nilai `buttonState` kemudian ditampilkan di serial monitor untuk pemantauan.

   Berdasarkan nilai `buttonState`, program memutuskan apakah push button ditekan atau tidak. Jika `buttonState` bernilai `HIGH`, artinya push button ditekan, maka program akan menyalakan LED dengan menggunakan `digitalWrite(ledPin, HIGH)`. Jika tidak ditekan, maka LED dimatikan dengan menggunakan `digitalWrite(ledPin, LOW)`.
<br></br>

# GPIO 4
Program pertama akan digunakan untuk mengendalikan LED agar blink setiap 500 ms ketika push button ke-2 ditekan.

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 2 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 2 buah

2. Rangkaian

    ![Rangkaian GPIO 4](https://github.com/alfan459/Embedded-System/assets/54757609/389106d1-e4a8-41c3-8bed-ea941e62d3db)

3. Program

    ![beautify-picture (6)](https://github.com/JustBadrun/Embeded_System/assets/128286595/a4bb49d1-7a78-41b6-8ad1-83935a81274c)

4. Flowchart

    ![Flowchart4](https://github.com/alfan459/Embedded-System/assets/54757609/f07744f4-de61-4698-a3f8-3103998632a0)

5. Hasil dan Pembahasan

    ![GPIO 4](https://github.com/alfan459/Embedded-System/assets/54757609/5c06b0e8-8ff4-441a-baa4-7ff00b3c4a38)

   Kode di atas adalah program untuk mengendalikan dua LED (LED1 dan LED2) menggunakan dua push button (button1 dan button2) pada ESP32. Berikut adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

  * Inisialisasi PIN dan Variabel:
   ```cpp
   const int button1 = 4;  // Button1 dihubungkan pada pin GPIO4
   const int button2 = 2;  // Button2 dihubungkan pada pin GPIO2
   const int led1 = 5;     // LED1 dihubungkan pada pin GPIO 5
   const int led2 = 18;     // LED2 dihubungkan pada pin GPIO 18

   int buttonState1 = 0;   // Variabel untuk menyimpan keadaan button1, 0 atau 1
   int buttonState2 = 0;   // Variabel untuk menyimpan keadaan button2, 0 atau 1
   int ledState = LOW;     // Kondisi yang akan digunakan untuk set LED
   unsigned long previousMillis = 0;  // Waktu terakhir LED ngeblink
   const long interval = 500;         // Interval untuk blink (milliseconds)
   ```

   Kode ini menetapkan bahwa button1 dan button2 akan dihubungkan ke pin GPIO 4 dan 2, sedangkan LED1 dan LED2 dihubungkan ke pin GPIO 5 dan 18. Variabel `buttonState1` dan `buttonState2` akan digunakan untuk menyimpan keadaan (HIGH atau LOW) dari button1 dan button2, dan variabel `ledState` digunakan untuk mengatur kondisi LED.

  * Setup:
   ```cpp
   void setup() {
     // Menginisialisasi button sebagai input
     pinMode(button1, INPUT);
     pinMode(button2, INPUT);

     // Menginisialisasi LED sebagai output
     pinMode(led1, OUTPUT);
     pinMode(led2, OUTPUT);
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, pin untuk button1, button2, led1, dan led2 diinisialisasi sebagai input atau output sesuai dengan kebutuhan.

  * Loop Utama:
   ```cpp
   void loop() {
     unsigned long currentMillis = millis();

     // Membaca kondisi button1 dan button2
     buttonState1 = digitalRead(button1);
     buttonState2 = digitalRead(button2);

     // Jika button1 ditekan maka LED1 akan menyala, jika tidak maka LED1 akan mati
     if (buttonState1 == HIGH) {
       digitalWrite(led1, HIGH);
     } else {
       digitalWrite(led1, LOW);
     }

     // Jika button2 ditekan maka kedua LED akan blink dengan interval 500ms
     if (buttonState2 == HIGH) {
       if (currentMillis - previousMillis >= interval) {
         previousMillis = currentMillis;

         // Jika ledState dalam keadaan mati, maka nyalakan dan sebaliknya
         if (ledState == LOW) {
           ledState = HIGH;
         } else {
           ledState = LOW;
         }

         // Atur nyala atau mati LED1 dan LED2 sesuai dengan nilai variabel ledState
         digitalWrite(led1, ledState);
         digitalWrite(led2, ledState);
       }
     }
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, program membaca kondisi dari button1 dan button2 menggunakan `digitalRead()`. Berdasarkan kondisi tersebut, program menyalakan atau mematikan LED1 sesuai dengan keadaan button1. Selain itu, jika button2 ditekan, kedua LED (LED1 dan LED2) akan melakukan blinking dengan interval 500ms menggunakan variabel `ledState` dan `previousMillis`.

<br></br>

# GPIO 5
Program pertama akan digunakan untuk membuat LED menyala bergantian dari kiri ke kanan ketika push button ke-3 ditekan.

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 5 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 3 buah

2. Rangkaian

    ![Rangkaian GPIO 5](https://github.com/alfan459/Embedded-System/assets/54757609/81dfe4c2-b0fe-4576-8de2-ab5ee3ced849)

3. Program

    ![beautify-picture (7)](https://github.com/JustBadrun/Embeded_System/assets/128286595/d9fd67d0-3873-4509-8529-c65293680460)

4. Flowchart

    ![Flowchart5](https://github.com/alfan459/Embedded-System/assets/54757609/f33ec0e3-478f-4588-b53f-67eb0437223b)

5. Hasil dan Pembahasan

    ![GPIO 5](https://github.com/alfan459/Embedded-System/assets/54757609/e9fa7683-f447-4b10-9758-9ef9b0d55a98)

    Kode di atas adalah program untuk mengendalikan beberapa LED (LED1 hingga LED5) menggunakan tiga push button (button1, button2, dan button3) pada platform Arduino atau mikrokontroler sejenis. Berikut adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

  * Inisialisasi PIN dan Variabel:
   ```cpp
   const int button1 = 4;    // Button1 dihubungkan pada pin GPIO4
   const int button2 = 2;    // Button2 dihubungkan pada pin GPIO5
   const int button3 = 15;   // Button3 dihubungkan pada pin GPIO6
   const int led1 = 5;       // LED1 dihubungkan pada pin GPIO7
   const int led2 = 18;      // LED2 dihubungkan pada pin GPIO8
   const int led3 = 19;      // LED3 dihubungkan pada pin GPIO9
   const int led4 = 21;      // LED4 dihubungkan pada pin GPIO10
   const int led5 = 3;       // LED5 dihubungkan pada pin GPIO11

   int buttonState1 = 0;     // Variabel untuk menyimpan keadaan button1, 0 atau 1
   int buttonState2 = 0;     // Variabel untuk menyimpan keadaan button2, 0 atau 1
   int buttonState3 = 0;     // Variabel untuk menyimpan keadaan button3, 0 atau 1
   int ledState = LOW;       // Kondisi yang akan digunakan untuk set LED
   unsigned long previousMillis = 0;  // Waktu terakhir LED ngeblink
   const long interval = 500;         // Interval untuk blink (milliseconds)
   ```

   Kode ini menetapkan pin untuk button1, button2, button3, led1, led2, led3, led4, dan led5. Variabel `buttonState1`, `buttonState2`, dan `buttonState3` akan digunakan untuk menyimpan keadaan (HIGH atau LOW) dari button1, button2, dan button3, sedangkan variabel `ledState` digunakan untuk mengatur kondisi LED.

  * Setup:
   ```cpp
   void setup() {
     // Menginisialisasi button sebagai input
     pinMode(button1, INPUT);
     pinMode(button2, INPUT);
     pinMode(button3, INPUT);

     // Menginisialisasi LED sebagai output
     pinMode(led1, OUTPUT);
     pinMode(led2, OUTPUT);
     pinMode(led3, OUTPUT);
     pinMode(led4, OUTPUT);
     pinMode(led5, OUTPUT);
   }
   ```

   Fungsi `setup()` dijalankan sekali pada awal program. Di dalamnya, pin untuk button1, button2, button3, led1, led2, led3, led4, dan led5 diinisialisasi sebagai input atau output sesuai dengan kebutuhan.

  * Loop Utama:
   ```cpp
   void loop() {
     unsigned long currentMillis = millis();

     // Membaca kondisi button1, button2, dan button3
     buttonState1 = digitalRead(button1);
     buttonState2 = digitalRead(button2);
     buttonState3 = digitalRead(button3);

     // Jika button1 ditekan maka LED1 akan menyala
     if (buttonState1 == HIGH) {
       digitalWrite(led1, HIGH);
     }
     // Jika tidak maka LED1 akan mati
     else {
       digitalWrite(led1, LOW);
     }

     // Jika button2 ditekan maka kedua LED akan blink dengan interval 500ms
     if (buttonState2 == HIGH) {
       if (currentMillis - previousMillis >= interval) {
         previousMillis = currentMillis;

         // Jika ledState dalam keadaan mati, maka nyalakan dan sebaliknya
         if (ledState == LOW) {
           ledState = HIGH;
         } else {
           ledState = LOW;
         }

         // Atur nyala atau mati LED1 dan LED2 sesuai dengan nilai variabel ledState
         digitalWrite(led1, ledState);
         digitalWrite(led2, ledState);
       }
     }

     // Jika button3 ditekan, maka running LED
     if (buttonState3 == HIGH) {
       // Running LED dari kiri ke kanan
       // ...
       
       // Running LED dari kanan ke kiri
       // ...
     }
   }
   ```

   Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, program membaca kondisi dari button1, button2, dan button3 menggunakan `digitalRead()`. Berdasarkan kondisi tersebut, program menyalakan atau mematikan LED1 sesuai dengan keadaan button1. Selain itu, jika button2 ditekan, kedua LED (LED1 dan LED2) akan melakukan blinking dengan interval 500ms menggunakan variabel `ledState` dan `previousMillis`. Jika button3 ditekan, LED3, LED4, dan LED5 akan melakukan efek running dari kiri ke kanan dan dari kanan ke kiri.
