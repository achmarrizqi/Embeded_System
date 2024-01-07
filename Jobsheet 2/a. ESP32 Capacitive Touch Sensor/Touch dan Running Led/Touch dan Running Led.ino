// Mengatur pin
const int touchPin = 4;        // Pin Touch yakni di GPIO4    
const int led1 = 16;           // LED1 dihubungkan pada GPIO16
const int led2 = 17;            // LED2 dihubungkan pada GPIO17
const int led3 = 18;            // LED3 dihubungkan pada GPIO18

const int threshold = 20;      // mengatur nilai treshold 
int touchValue;                // variable untuk menympan nilai touch pin

void setup(){
  Serial.begin(115200);        // komunikasi serial diatur pada baudrate 115200 
  delay(1000);                 // delay awal 
  // inisialisasi LED sebagai output:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);    
}

void loop(){
  touchValue = touchRead(touchPin);    // membaca nilai touch
  Serial.print(touchValue);            // menampilkan nilai touch ke serial monitor
  
  // Jika nilai touch lebih kecil dari nilai treshold, maka lampu akan blink
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);

    // Kanan ke Kiri
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
  }
  // Jika tidak, matikan lampu
  else{
    // turn LED off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  delay(500);
}
