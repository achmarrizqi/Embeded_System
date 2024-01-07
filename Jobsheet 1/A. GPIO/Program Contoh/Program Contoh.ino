// mengatur pin
const int buttonPin = 4;    // pin 4 terhubung ke push button
const int ledPin = 5;       // pin 5 terhubung ke LED

// menambahkan variable untuk menyimpan keadaan pushbutton
int buttonState = 0;

void setup() {
  Serial.begin(115200);       // komunikasi serial diatur di 115200
  pinMode(buttonPin, INPUT);  // inisialisasi pushbutton sebagai input
  pinMode(ledPin, OUTPUT);    // inisialisasi led sebagai output
}

void loop() {
  buttonState = digitalRead(buttonPin);    // membaca nilai pushbutton secara digital dan menyimpannya ke variable buttonState
  Serial.println(buttonState);             // menampilkan nilai buttonState di serial monitor
  
  // Jika buttonState bernilai HIGH atau pushbutton ditekan, maka akan menyalakan led
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);            // menyalakan led
  } 
  // Jika tidak ditekan, maka matikan lampu
  else {
    digitalWrite(ledPin, LOW);             // mematikan led
  }
}
