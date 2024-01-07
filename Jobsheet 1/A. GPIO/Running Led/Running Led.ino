// mengatur posisi PIN
const int button1 = 4;    // button1 dihubungkan pada pin GPIO4
const int button2 = 2;  // button2 dihubungkan pada pin GPIO5
const int button3 = 15;  // button3 dihubungkan pada pin GPIO6
const int led1 = 5;     // LED1 dihubungkan pada pin GPIO 7
const int led2 = 18;     // LED2 dihubungkan pada pin GPIO 8
const int led3 = 19;     // LED3 dihubungkan pada pin GPIO 9
const int led4 = 21;    // LED4 dihubungkan pada pin GPIO 10
const int led5 = 3;    // LED5 dihubungkan pada pin GPIO 11

// variable untuk menyimpan keadaan button, 0 atau 1
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

// variable untuk keadaan Led
int ledState = LOW;                // kondisi yang akan digunakan untuk set LED
unsigned long previousMillis = 0;  // waktu Led setelah mati
const long interval = 500;         // interval untuk blink (milliseconds)

void setup() {
  // menginisialisasi button sebagai input
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // menginisialisasi LED sebagai output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  // membaca kondisi button
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);

  // Jika button1 ditekan maka led1 akan menyala
  if (buttonState1 == HIGH) {
    digitalWrite(led1, HIGH);
  }
  // Jika tidak maka led1 akan mati
  else {
    digitalWrite(led1, LOW);
  }

  // Jika button2 ditekan maka kedua led akan blink 500ms
  if (buttonState2 == HIGH) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;  // Menyimpan waktu terakhir LED ngeblink

      // jika led dalam keadaan mati, maka nyalakan dan sebaliknya
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      // atur nyala atau mati LED sesuai dengan nilai variable ledState
      digitalWrite(led1, ledState);
      digitalWrite(led2, ledState);
    }
  }

  // Jika button3 ditekan, maka running led
  if (buttonState3 == HIGH) {
    // Kiri ke kanan
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(100);

    // Kanan ke Kiri
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(100);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(100);
  }
}
