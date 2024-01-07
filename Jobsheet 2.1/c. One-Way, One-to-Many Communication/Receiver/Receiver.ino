// Menambahkan Library ESPNOW dan WiFi
#include <esp_now.h>
#include <WiFi.h>

// Struktur pesan sender dan receiver harus sama
typedef struct test_struct {
  int x;
  int y;
} test_struct;

// Buat sebuah struct_message dengan nama myData
test_struct myData;

// fungsi callback yang akan dieksekusi ketika pesan diterima
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("x: ");
  Serial.println(myData.x);
  Serial.print("y: ");
  Serial.println(myData.y);
  Serial.println();
}

void setup() {
  // Komunikasi serial diatur pada baudrate 115200:
  Serial.begin(115200);

  // Set ESP32 sebagai station
  WiFi.mode(WIFI_STA);

  // Inisialisasi ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
void loop() {
}
