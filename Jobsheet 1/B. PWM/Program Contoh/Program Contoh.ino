// mengatur pin yang terhubung ke LED
const int ledPin = 16;            // LED terhubung ke pin GPIO16

// Mengatur pengaturan PWM
const int freq = 5000;
const int ledChannel = 0;         //PWM Channel
const int resolution = 8;         //resolution bit

void setup() {
  // Mengkonfigurasi PWM LED
  ledcSetup(ledChannel, freq, resolution);

  // menghubungkan channel ke GPIO agar bisa dikendalikan
  ledcAttachPin(ledPin, ledChannel);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
}

void loop() {
  // meningkatkan cahaya LED
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    // mengatur keterangan cahaya LED dengan PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }
  // mengurangi cahaya LED
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    // mengatur keterangan cahaya LED dengan PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }
}
