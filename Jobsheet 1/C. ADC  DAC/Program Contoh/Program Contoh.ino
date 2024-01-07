// Potentiometer terhubung ke GPIO34 (Analog ADC1_CH6)
const int potPin = 34;

// variable untuk menyimpan nilai potensiometer
int potValue = 0;

void setup() {
  Serial.begin(115200);           // Serial diatur di baudrate 115200
  delay(1000);                    // jeda waktu pertama kali
}
void loop() {
  
  // Membaca nilai potensiometer
  potValue = analogRead(potPin);
  Serial.println(potValue);       // Menampilkan nilai potensio ke serial monitor
  delay(500);
}
