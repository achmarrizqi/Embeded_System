void setup() {
  Serial.begin(115200);     // komunikasi serial diatur pada baudrate 115200 
  delay(1000);              // delay awal 
  Serial.println("ESP32 Touch Test");
}
void loop() {
  Serial.println(touchRead(4));  //mendapatkan nilai dari Touch 0 pin = GPIO 4
  delay(1000);
}
