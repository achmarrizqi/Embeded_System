// mengatur posisi PIN
const int ledPin = 5;               // LED dihubungkan pada pin GPIO 5

// variable untuk keadaan Led
int ledState = LOW;                 // kondisi yang akan digunakan untuk set LED
unsigned long previousMillis = 0;   // waktu Led setelah mati
const long interval = 1000;         // interval untuk blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);          // Menginisialisasi LED sebagai Output
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;                     // Menyimpan waktu terakhir LED ngeblink

    // jika led dalam keadaan mati, maka nyalakan dan sebaliknya
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // atur nyala atau mati LED sesuai dengan nilai variable ledState
    digitalWrite(ledPin, ledState);
  }
}
