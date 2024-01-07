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
}
