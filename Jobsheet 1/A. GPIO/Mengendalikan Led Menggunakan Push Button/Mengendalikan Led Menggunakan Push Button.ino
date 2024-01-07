// mengatur posisi PIN
const int button1 = 4;  // button1 dihubungkan pada pin GPIO4
const int button2 = 6;  // button2 dihubungkan pada pin GPIO6
const int led1 = 5;     // LED1 dihubungkan pada pin GPIO 5
const int led2 = 7;     // LED2 dihubungkan pada pin GPIO 7

// variable untuk menyimpan keadaan button, 0 atau 1
int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  // menginisialisasi button sebagai input
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
  // menginisialisasi LED sebagai output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // membaca kondisi button 
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
    
  // Jika button ditekan maka lampu akan menyala
  if (buttonState1 == HIGH) {
    digitalWrite(led1, HIGH);
  } 
  // Jika tidak maka lampu akan mati
  else {
    digitalWrite(led1, LOW);
  }

  if(buttonState2 == HIGH){
    digitalWrite(led2, HIGH);
  }
}
