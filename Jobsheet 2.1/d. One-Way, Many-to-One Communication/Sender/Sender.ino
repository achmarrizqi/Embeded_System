// Menambahkan Library ESPNOW dan WiFi
#include <esp_now.h>
#include <WiFi.h>

// ganti dengan alamat MAC penerima
uint8_t broadcastAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

// Struktur pesan sender dan receiver harus sama
typedef struct struct_message {
  int id;  // must be unique for each sender board
  int x;
  int y;
} struct_message;

// Buat struct_message dengan nama myData
struct_message myData;

// Buat peer interface
esp_now_peer_info_t peerInfo;

// fungsi callback ketika data terkirim
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
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

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Menambahkan peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Atur nilai untuk dikirimkan
  myData.id = 1;
  myData.x = random(0, 50);
  myData.y = random(0, 50);
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&myData,
                                  sizeof(myData));
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }
  delay(10000);
}
