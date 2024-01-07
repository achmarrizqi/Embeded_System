const int led1 = 16;           // LED1 dihubungkan pada GPIO16
const int led2 = 18;            // LED2 dihubungkan pada GPIO18
const int led3 = 19;            // LED3 dihubungkan pada GPIO19
const int buzzer = 10;         // buzzer dihubungkan pada GPIO10

// Menambahkan library DHT
#include "DHT.h"

#define DHTPIN 4            // Digital pin terhubung ke DHT sensor

// Uncomment type yang tidak digunakan
#define DHTTYPE DHT11       // DHT 11
//#define DHTTYPE DHT22     // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21     // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);       // komunikasi serial diatur ke baudrate 9600
  Serial.println(F("DHT11 Embedded System Test!"));
  dht.begin();              // memulai komunikasi dht

  // inisialisasi LED sebagai output:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
}
void loop() {
  // jeda antar pengukuran.
  delay(2000);
  
  // Pembacaan suhu atau kelembapan sekitar 250 milliseconds!
  float h = dht.readHumidity();
  // membaca suhu sebagai Celsius (the default)
  float t = dht.readTemperature();
  // membaca suhu sebagai Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // cek jika ada pembacaan yang salah atau gagal agar bisa memulai ulang
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Hitung heat index dalam Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Hitung heat index in Celsius (isFahreheit = false)
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

  // Jika suhu berada dibawah 30 derajat, maka running led:
  if(t < 30.00 || t == 30.00){
   digitalWrite(led1, HIGH);
   digitalWrite(buzzer, HIGH);
   delay(1000);
   digitalWrite(buzzer, LOW);
   delay(1000);
  }
  
  else{
    digitalWrite(buzzer, LOW);
    // turn LED on
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);

    // Kanan ke Kiri
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
  }
}
