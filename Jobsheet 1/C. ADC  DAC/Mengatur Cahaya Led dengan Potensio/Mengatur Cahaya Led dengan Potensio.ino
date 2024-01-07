#include <Arduino.h>
#include <analogWrite.h>

const int analogInPin = 34;       // Analog input pin dimana potentiometer akan terhubung
const int analogOutPin = 5;       // Analog output pin dimana LED akan terhubung

// mengatur pengaturan PWM
const int freq = 5000;
const int ledChannel = 0;         // PWM channel
const int resolution = 8;         // resolution

int sensorValue = 0;
int outputValue = 0;

void setup() {
  // membaca nilai potensio
  // nilai output akan dikirimkan ke AnalogOut
  
  Serial.begin(115200);           // komunikasi serial diatur pada baudrate 115200
  
  // mengkonfigurasi LED PWM
  ledcSetup(ledChannel, freq, resolution);
  
  // menghubungkan Channel ke GPIO untuk dihubungkan
  ledcAttachPin(analogOutPin, ledChannel);
}

void loop() {
  sensorValue = analogRead(analogInPin);            // membaca nilai analog
  outputValue = map(sensorValue, 0, 4095, 0, 255);  // map untuk range nilai analog
  analogWrite(analogOutPin, outputValue);           // atur nilai analogOut

  // tampilkan hasilnya ke serial monitor
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  

  // tunggu 2 miliseconds sebelum loop selanjutnya untuk ADC
  delay(2);
}
