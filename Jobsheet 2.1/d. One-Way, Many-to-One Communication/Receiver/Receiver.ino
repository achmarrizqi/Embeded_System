// Menambahkan Library ESPNOW dan WiFi
#include <esp_now.h>
#include <WiFi.h>

// Struktur pesan sender dan receiver harus sama
typedef struct struct_message {
  int id;
  int x;
  int y;
} struct_message;

// Buat sebuah struct_message dengan nama myData
struct_message myData;

// Buat sebuah structure untuk menahan pembacaan pada setiap board
struct_message board1;
struct_message board2;
struct_message board3;

// Buat sebuah array dengan semua structure
struct_message boardsStruct[3] = { board1, board2, board3 };

// fungsi callback yang akan dieksekusi ketika pesan diterima
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *incomingData, int len) {
  char macStr[18];
  Serial.print("Packet received from: ");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4],
           mac_addr[5]);
  Serial.println(macStr);
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.printf("Board ID %u: %u bytes\n", myData.id, len);

  // Update structure dengan data yang baru
  boardsStruct[myData.id - 1].x = myData.x;
  boardsStruct[myData.id - 1].y = myData.y;
  Serial.printf("x value: %d \n", boardsStruct[myData.id - 1].x);
  Serial.printf("y value: %d \n", boardsStruct[myData.id - 1].y);
  Serial.println();
}

void setup() {
  // Komunikasi serial diatur pada baudrate 115200:
  Serial.begin(115200);

  // Set ESP32 sebagai station
  WiFi.mode(WIFI_STA);

  //Inisialisasi ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}
void loop() {
  // Acess the variables for each board
  /*int board1X = boardsStruct[0].x; 
int board1Y = boardsStruct[0].y; 
int board2X = boardsStruct[1].x; 
int board2Y = boardsStruct[1].y; 
int board3X = boardsStruct[2].x; 
int board3Y = boardsStruct[2].y;*/
  delay(10000);
}
