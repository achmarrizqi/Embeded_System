// Mengatur pin
const int touchPin = 4;        // Pin Touch yakni di GPIO4    
const int ledPin = 16;         // Pin LED dihubungkan pada GPIO16

const int threshold = 20;      // mengatur nilai treshold 
int touchValue;                // variable untuk menympan nilai touch pin

void setup(){
  Serial.begin(115200);        // komunikasi serial diatur pada baudrate 115200 
  delay(1000);                 // delay awal 
  pinMode (ledPin, OUTPUT);    // inisialisasi LED sebagai output
}

void loop(){
  touchValue = touchRead(touchPin);    // membaca nilai touch
  Serial.print(touchValue);            // menampilkan nilai touch ke serial monitor
  
  // Jika nilai touch lebih kecil dari nilai treshold, maka nyalakan lampu
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(ledPin, HIGH);
    Serial.println(" - LED on");
  }
  // Jika tidak, matikan lampu
  else{
    // turn LED off
    digitalWrite(ledPin, LOW);
    Serial.println(" - LED off");
  }
  delay(500);
}
