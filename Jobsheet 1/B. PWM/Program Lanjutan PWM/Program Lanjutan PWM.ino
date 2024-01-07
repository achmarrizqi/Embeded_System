// mengatur pin yang terhubung ke LED
const int ledPin = 16;   // LED1 terhubung ke pin GPIO16
const int ledPin2 = 17;  // LED2 terhubung ke pin GPIO17
const int ledPin3 = 5;   // LED3 terhubung ke pin GPIO5

// Mengatur pengaturan PWM
const int freq = 5000;
const int ledChannel = 0;  // PWM Channel
const int resolution = 8;  // resolution bit

void setup() {
  // Mengkonfigurasi PWM LED
  ledcSetup(ledChannel, freq, resolution);

  // menghubungkan channel ke GPIO agar bisa dikendalikan
  ledcAttachPin(ledPin, ledChannel);
  ledcAttachPin(ledPin2, ledChannel);
  ledcAttachPin(ledPin3, ledChannel);
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
