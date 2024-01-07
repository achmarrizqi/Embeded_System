// Menambahkan Library ESPNOW dan WiFi
#include <esp_now.h>
#include <WiFi.h>

// ganti dengan alamat MAC penerima
uint8_t broadcastAddress1[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
uint8_t broadcastAddress2[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
uint8_t broadcastAddress3[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

// Struktur pesan sender dan receiver harus sama
typedef struct test_struct {
  int x;
  int y;
} test_struct;
test_struct test;

// Driver untuk struktur pesan
esp_now_peer_info_t peerInfo;

// fungsi callback ketika data terkirim
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  Serial.print("Packet to: ");
  // Salin alamat MAC pengirim ke sebuah string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4],
           mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail"); 
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

  esp_now_register_send_cb(OnDataSent);

  // register peer
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  // register first peer
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
  // register second peer
  memcpy(peerInfo.peer_addr, broadcastAddress2, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
  /// register third peer
  memcpy(peerInfo.peer_addr, broadcastAddress3, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  test.x = random(0, 20);
  test.y = random(0, 20);

  esp_err_t result = esp_now_send(0, (uint8_t *)&test, sizeof(test_struct));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }
  delay(2000);
}
