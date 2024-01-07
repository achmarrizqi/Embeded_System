# B. Transmisi Data Menggunakan Protokol HTTP

## 1. Keterangan Singkat (Abstrak)
<p align="justify">Percobaan ini dimulai dengan pembuatan database lokal "banjir_db" dan tabel "smartwater" menggunakan phpMyAdmin. Lalu diberikan kode JSON untuk flow program Multi-Protocol IoT Server yang perlu diimport di Node-RED. Selanjutnya, melalui program pada ESP32 dilakukan transmisi data dummy ke Node-Red menggunakan protokol HTTP metode GET dan protokol HTTP metode POST. Output dari percobaan ini berupa hasil dari serial monitor, debugging Node-Red, dan tampilan dashboard Node-RED.
   
## 2. Alat dan Bahan
1. Node-RED
2. ESP32
3. XAMPP

## 3. Source Code

1. Code JSON Multi-Protocol IoT Server dapat dilihat <a href="https://github.com/JustBadrun/Embeded_System/blob/014c31a7786acec166eb84f8575ea29c590a43d6/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/flow%20program%20Multi-Protocol%20IoT.json">disini</a>
2. Program ESP32 transmisi data dummy menggunakan protokol HTTP metode GET dapat dilihat <a href="https://github.com/JustBadrun/Embeded_System/blob/9ab6346c50179de04fe61cd0294bd7dd65c6f647/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/transmisi_data_dummy_keNode-Red_protokol_HTTP_metode_Get/transmisi_data_dummy_keNode-Red_protokol_HTTP_metode_Get.ino">disini</a>
3. Program ESP32 transmisi data dummy menggunakan protokol HTTP metode POST dapat dilihat <a href="https://github.com/JustBadrun/Embeded_System/blob/f67159702c58767bad46a8e4fbd698aec8c29349/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/transmisi_data_dummy_ke_Node-Red_protokol_HTTP_metode_POST/transmisi_data_dummy_ke_Node-Red_protokol_HTTP_metode_POST.ino">disini</a>

## 4. Flow Program
![flow program ](https://github.com/JustBadrun/Embeded_System/assets/128286595/aa591bb8-08f0-440f-9152-8d4e04e4d1ef)


## 5. Hasil Percobaan Transmisi Data Dummy Menuju Node-Red Menggunakan Protokol HTTP Metode GET
### Dokumentasi Percobaan

1. Flow chart program ESP32
   
   ![Flow Get](https://github.com/JustBadrun/Embeded_System/assets/128286595/a980cef2-565c-4529-8f59-ddac44928c39)

   
2. Output serial monitor
   
   ![serial monitor-metode get](https://github.com/JustBadrun/Embeded_System/assets/128286595/95efca05-5381-4659-a18d-ee3517cd6221)
   
3. Debug Node-RED
   
  ![debug-metode GET](https://github.com/JustBadrun/Embeded_System/assets/128286595/3980b3b8-1f65-49ba-97c3-d55c6d86a056)
   
4. Dashboard Node-RED
   
   ![dashboard-metode get](https://github.com/JustBadrun/Embeded_System/assets/128286595/206fbdd1-facc-488e-89c3-ae2d99a432f4)
   
5. Tabel database MySQL
   
   ![tabel smartwater-metode get](https://github.com/JustBadrun/Embeded_System/assets/128286595/25f56dd1-f7a9-4e7e-9022-fbf8d4d205dd)

### Penjelasan Kode
![Get](https://github.com/JustBadrun/Embeded_System/assets/128286595/a294b978-7bf1-4681-b26e-89792fa62854)

Kode tersebut adalah program ESP32 yang menggunakan perangkat WiFi (menggunakan library WiFi.h dan HTTPClient.h) untuk mengirimkan permintaan HTTP GET ke suatu server. Penjelasan dari kode tersebut berada di bawa ini:
1. **Inklusi Library:**
   ```cpp
   #include <WiFi.h>
   #include <HTTPClient.h>
   ```
   Dua library digunakan: WiFi.h untuk mengelola koneksi WiFi, dan HTTPClient.h untuk melakukan permintaan HTTP.

2. **Konfigurasi Koneksi WiFi:**
   ```cpp
   const char* ssid = "1165342";
   const char* password = "kitabisa";
   ```
   Nama dan kata sandi WiFi yang digunakan untuk mengakses jaringan.

3. **Konfigurasi Server:**
   ```cpp
   String serverName = "http://192.168.1.12:1880/flood/node1";
   ```
   Alamat URL server yang akan menerima permintaan HTTP GET. IP dan path disesuaikan dengan konfigurasi server yang sebenarnya.

4. **Inisialisasi Variabel:**
   ```cpp
   unsigned long lastTime = 0;
   unsigned long timerDelay = 5000;
   ```
   Variabel untuk melacak waktu terakhir permintaan HTTP GET dan interval waktu antar permintaan.

5. **Setup Function:**
   ```cpp
   void setup() {
     // Inisialisasi Serial dan koneksi WiFi
     Serial.begin(115200);
     WiFi.begin(ssid, password);
     
     Serial.println("Connecting");
     while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.print(".");
     }
     
     Serial.println("");
     Serial.print("Connected to WiFi network with IP Address: ");
     Serial.println(WiFi.localIP());
     
     Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
   }
   ```
   Fungsi setup yang pertama kali dijalankan saat perangkat dinyalakan. Menginisialisasi Serial, menghubungkan ke WiFi, dan mencetak informasi koneksi.

6. **Loop Function:**
   ```cpp
   void loop() {
     float dev_id = 28, level = 5, rainfall = 10.2, flow = 12;
     
     if ((millis() - lastTime) > timerDelay) {
       // Melakukan permintaan HTTP GET setiap 5 detik
       
       // Memeriksa status koneksi WiFi
       if (WiFi.status() == WL_CONNECTED) {
         HTTPClient http;
         String serverPath = serverName + "?dev_id=" + dev_id + "&level=" + level + "&rainfall=" + rainfall + "&flow=" + flow;
         
         // Membuka koneksi HTTP ke server
         http.begin(serverPath.c_str());
         
         // Mengirim permintaan HTTP GET
         int httpResponseCode = http.GET();
         
         // Memproses respons HTTP
         if (httpResponseCode > 0) {
           Serial.print("HTTP Response code: ");
           Serial.println(httpResponseCode);
           String payload = http.getString();
           Serial.println(payload);
         } else {
           Serial.print("Error code: ");
           Serial.println(httpResponseCode);
         }
         
         // Menutup koneksi HTTP dan melepaskan sumber daya
         http.end();
       } else {
         Serial.println("WiFi Disconnected");
       }
       
       // Memperbarui waktu terakhir permintaan
       lastTime = millis();
     }
   }
   ```
   Fungsi loop yang berjalan terus-menerus setelah fungsi setup selesai. Dalam loop ini, terdapat logika untuk mengirimkan permintaan HTTP GET ke server setiap 5 detik. Informasi seperti `dev_id`, `level`, `rainfall`, dan `flow` diatur secara manual dan dapat disesuaikan sesuai kebutuhan aplikasi. Jika koneksi WiFi terputus, pesan "WiFi Disconnected" akan dicetak.

## 6. Hasil Percobaan Transmisi Data Dummy Menuju Node-Red Menggunakan Protokol HTTP Metode POST
### Dokumentasi Percobaan

1. Flow chart program ESP32
   
   ![Flow Post](https://github.com/JustBadrun/Embeded_System/assets/128286595/54bf9f70-120b-4e56-a098-3a1d57006b04)

2. Output serial monitor
   
   ![serial monitor-metode POST](https://github.com/JustBadrun/Embeded_System/assets/128286595/00f50206-520b-4ef3-b7c2-e15b526e99aa)
   
3. Debug Node-RED
   
   ![debug-metode POST](https://github.com/JustBadrun/Embeded_System/assets/128286595/c43f71d6-98c0-4f27-b5cb-48fac635a03b)
   
4. Dashboard Node-RED
   
   ![dashboard-metode POST](https://github.com/JustBadrun/Embeded_System/assets/128286595/e8173772-417e-41b7-95ec-ebf0ef12a8b1)

### Penjelasan Kode
![POST](https://github.com/JustBadrun/Embeded_System/assets/128286595/a4ec0ec6-e5e8-4326-895e-0aa07088edbd)

Kode tersebut adalah program ESP32 yang menggunakan perangkat WiFi untuk mengirimkan permintaan HTTP POST ke suatu server secara berkala. Di bawah ini adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

1. **Inklusi Library:**
   ```cpp
   #include <WiFi.h>
   #include <HTTPClient.h>
   ```
   Library WiFi.h digunakan untuk mengelola koneksi WiFi, dan library HTTPClient.h untuk melakukan permintaan HTTP.

2. **Konfigurasi Koneksi WiFi:**
   ```cpp
   const char* ssid = "1163542";
   const char* password = "kitabisa";
   ```
   Nama dan kata sandi WiFi yang digunakan untuk mengakses jaringan.

3. **Konfigurasi Server:**
   ```cpp
   const char* serverName = "http://192.168.1.12:1880/flood/node1";
   ```
   Alamat URL server yang akan menerima permintaan HTTP POST. IP dan path disesuaikan dengan konfigurasi server yang sebenarnya.

4. **Inisialisasi Variabel:**
   ```cpp
   unsigned long lastTime = 0;
   unsigned long timerDelay = 5000;
   ```
   Variabel untuk melacak waktu terakhir permintaan HTTP POST dan interval waktu antar permintaan. Pada kode yang di-comment, interval waktu diatur menjadi 10 menit (`600000`).

5. **Setup Function:**
   ```cpp
   void setup() {
     // Inisialisasi Serial dan koneksi WiFi
     Serial.begin(115200);
     WiFi.begin(ssid, password);
     
     Serial.println("Connecting");
     while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.print(".");
     }
     
     Serial.println("");
     Serial.print("Connected to WiFi network with IP Address: ");
     Serial.println(WiFi.localIP());
     Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
   }
   ```
   Fungsi setup yang pertama kali dijalankan saat perangkat dinyalakan. Menginisialisasi Serial, menghubungkan ke WiFi, dan mencetak informasi koneksi.

6. **Loop Function:**
   ```cpp
   void loop() {
     String dev_id = "28", level = "8", rainfall = "9.2", flow = "10";
     
     if ((millis() - lastTime) > timerDelay) {
       // Melakukan permintaan HTTP POST setiap 5 detik
       
       // Memeriksa status koneksi WiFi
       if (WiFi.status() == WL_CONNECTED) {
         WiFiClient client;
         HTTPClient http;
         
         // Membuka koneksi HTTP ke server
         http.begin(client, serverName);
         
         // Menambahkan header untuk tipe konten
         http.addHeader("Content-Type", "application/json");
         
         // Data JSON untuk dikirimkan dengan HTTP POST
         String httpRequestData = "{\"dev_id\":\"" + dev_id + "\",\"level\":\"" + level + "\",\"rainfall\":\"" + rainfall + "\",\"flow\":\"" + flow + "\"}";
         
         // Mengirim permintaan HTTP POST
         int httpResponseCode = http.POST(httpRequestData);
         
         // Menampilkan respons HTTP
         Serial.print("HTTP Response code is: ");
         Serial.println(httpResponseCode);
         
         // Menutup koneksi HTTP
         http.end();
       } else {
         Serial.println("WiFi Disconnected");
       }
       
       // Memperbarui waktu terakhir permintaan
       lastTime = millis();
     }
   }
   ```
   Fungsi loop yang berjalan terus-menerus setelah fungsi setup selesai. Dalam loop ini, terdapat logika untuk mengirimkan permintaan HTTP POST ke server setiap 5 detik. Informasi seperti `dev_id`, `level`, `rainfall`, dan `flow` diatur secara manual dan dapat disesuaikan sesuai kebutuhan aplikasi. Jika koneksi WiFi terputus, pesan "WiFi Disconnected" akan dicetak.
