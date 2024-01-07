const int ledPin = 2; // Pin LED
const int touchPin = 4; // Pin sensor sentuh
int touchCount = 0; // Variabel untuk menghitung sentuhan

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    // Jika sensor sentuh disentuh, tambahkan 1 ke touchCount
    touchCount++;
    
    // Hidupkan LED
    digitalWrite(ledPin, HIGH);

    // Tampilkan touchCount di Serial Monitor
    Serial.print("Sentuhan ke-");
    Serial.println(touchCount);
    
    // Tunggu sebentar untuk menghindari deteksi berulang
    delay(500);
  } else {
    // Matikan LED jika sensor tidak disentuh
    digitalWrite(ledPin, LOW);
  }
}
