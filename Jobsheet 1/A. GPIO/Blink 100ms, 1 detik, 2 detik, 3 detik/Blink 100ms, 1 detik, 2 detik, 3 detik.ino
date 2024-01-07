// Mengatur posisi PIN
const int LedPin = 5;               // Led dihubungkan pada pin GPIO 5

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LedPin, OUTPUT);          // Inisialisasi Led sebagai OUTPUT
}

// the loop function runs over and over again forever
void loop() {
  // Nyala 100ms dan mati selama 1 detik
  digitalWrite(LedPin, HIGH);       // menyalakan LED
  delay(100);                       // akan menyala selama 100ms
  digitalWrite(LedPin, LOW);        // mematikan LED
  delay(1000);                      // akan mati selama 1 detik

  // Nyala 1 detik dan mati selama 1 detik
  digitalWrite(LedPin, HIGH);       // menyalakan LED
  delay(1000);                      // akan menyala selama 1 detik
  digitalWrite(LedPin, LOW);        // mematikan LED
  delay(1000);                      // akan mati selama 1 detik

  // Nyala 2 detik dan mati selama 1 detik
  digitalWrite(LedPin, HIGH);       // menyalakan LED
  delay(2000);                      // akan menyala selama 2 detik
  digitalWrite(LedPin, LOW);        // mematikan LED
  delay(1000);                      // akan mati selama 1 detik

  // Nyala 3 detik dan mati selama 1 detik
  digitalWrite(LedPin, HIGH);       // menyalakan LED
  delay(3000);                      // akan menyala selama 3 detik
  digitalWrite(LedPin, LOW);        // mematikan LED
  delay(1000);                      // akan mati selama 1 detik
}
