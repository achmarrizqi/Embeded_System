# C. Transmisi Data Menggunakan Protokol MQTT

## 1. Keterangan Singkat (Abstrak)
<p align="justify">Dalam percobaan ini, program ESP32 memanfaatkan protokol MQTT untuk mentransmisikan data dummy, seperti level, rainfall, dan flow. Server broker MQTT yang digunakan adalah layanan EMQ X, yang merupakan platform perangkat lunak open-source untuk implementasi MQTT. Setelah program diupload, dilakukan pemantauan melalui serial monitor untuk memastikan koneksi dan debug pada Node-Red. Hasil output dari percobaan ini meliputi data yang dipublikasikan ke topik "flood/node1", serta visualisasi data pada dashboard Node-Red.
   
## 2. Alat dan Bahan
1. Node-RED
2. ESP32
3. XAMPP

## 3. Source Code

1. Code JSON Multi-Protocol IoT Server dapat dilihat <a href="https://github.com/JustBadrun/Embeded_System/blob/779e3094c4a99662134e7666c512bfda461b98ba/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/flow%20program%20Multi-Protocol%20IoT.json">disini</a>
2. Program ESP32 dapat dilihat <a href="https://github.com/JustBadrun/Embeded_System/blob/ecd364c96cc7145edb31f6d7a8a85aa666848fba/Jobsheet%204/C.%20Transmisi%20Data%20Menggunakan%20Protokol%20MQTT/program%20transmisi%20mqtt/program%20transmisi%20mqtt.ino">disini</a>

## 4. Flow Program
![flow program ](https://github.com/JustBadrun/Embeded_System/assets/128286595/fe8627e8-997f-4fff-89bd-b89c87a93d8a)

## 5. Hasil & Pembahasan
### Dokumentasi Hasil

1. Flow chart program ESP32
   
   ![Flow mqtt](https://github.com/JustBadrun/Embeded_System/assets/128286595/2ee54177-253b-4d5e-aaaf-b5b764efe352)
   
2. Output serial monitor
   
   ![serial monitor](https://github.com/JustBadrun/Embeded_System/assets/128286595/6383bc42-7dce-4ec9-9754-3ca267b12e42)
   
3. Debug Node-RED
   
   ![debug](https://github.com/JustBadrun/Embeded_System/assets/128286595/c8237369-bb64-4939-8706-885fa5638542)
   
4. Dashboard Node-RED
   
   ![dashboard](https://github.com/JustBadrun/Embeded_System/assets/128286595/3e3de2a7-c0bc-448e-85a6-5a2880c2a84d)
   
5. Tabel database MySQL
   
   ![database](https://github.com/JustBadrun/Embeded_System/assets/128286595/824f00da-c064-42fe-91de-04e4b0f717b1)

### Penjelasan Kode
![beautify-picture](https://github.com/JustBadrun/Embeded_System/assets/128286595/4376f128-4ad7-43c9-85d9-72118cb8c3b7)

Kode di atas adalah program ESP32 yang menggunakan modul WiFi untuk mengirimkan data melalui protokol MQTT ke suatu server MQTT publik broker.emqx.io. Berikut penjelasan singkat untuk setiap bagian dari kode tersebut:

1. **Inklusi Library:**
   ```cpp
   #include <WiFi.h>
   #include <PubSubClient.h>
   #include <ArduinoJson.h>
   ```
   Library WiFi.h digunakan untuk mengelola koneksi WiFi, library PubSubClient.h untuk mengimplementasikan klien MQTT, dan library ArduinoJson.h untuk memproses dan membangun data JSON.

2. **Konfigurasi Koneksi WiFi dan MQTT Server:**
   ```cpp
   const char* ssid = "ZTE_2.4G_TuYTR4";
   const char* password = "kasnaman1";
   const char* mqtt_server = "broker.emqx.io";
   ```
   Nama dan kata sandi WiFi, serta alamat MQTT broker yang digunakan.

3. **Inisialisasi Objek Klien WiFi dan MQTT:**
   ```cpp
   WiFiClient espClient;
   PubSubClient client(espClient);
   ```
   Inisialisasi objek klien WiFi dan klien MQTT dengan menggunakan objek klien WiFi.

4. **Fungsi Setup WiFi:**
   ```cpp
   void setup_wifi() {
     // ...
   }
   ```
   Fungsi ini menginisialisasi koneksi WiFi. Menunggu koneksi ke jaringan WiFi dan mencetak informasi IP setelah terkoneksi.

5. **Fungsi Reconnect MQTT:**
   ```cpp
   void reconnect() {
     // ...
   }
   ```
   Fungsi ini mencoba kembali terhubung ke broker MQTT jika koneksi terputus.

6. **Fungsi Setup:**
   ```cpp
   void setup() {
     // ...
   }
   ```
   Fungsi setup yang pertama kali dijalankan saat perangkat dinyalakan. Memulai serial, menginisialisasi koneksi WiFi, dan mengatur server MQTT.

7. **Fungsi Loop:**
   ```cpp
   void loop() {
     // ...
   }
   ```
   Fungsi loop yang berjalan terus-menerus setelah fungsi setup selesai. Jika koneksi MQTT terputus, akan mencoba kembali terhubung. Membaca data sensor (dalam bentuk objek JSON) dan mengirimkannya melalui MQTT setiap 10 detik.

8. **Pengiriman Data MQTT:**
   ```cpp
   char payload[200];
   StaticJsonBuffer<200> jsonBuffer;
   JsonObject& doc = jsonBuffer.createObject();
   doc["dev_id"] = 28;
   doc["level"] = 25;
   doc["rainfall"] = 5.25;
   doc["flow"] = 10;
   doc.printTo(payload);
   client.publish("flood/node1", payload);
   delay(10000);
   ```
   Bagian ini membuat objek JSON menggunakan ArduinoJson, mengonversi objek JSON tersebut menjadi string, dan kemudian mengirimkannya ke topik "flood/node1" pada broker MQTT. Data ini dikirim setiap 10 detik dengan menggunakan delay.

