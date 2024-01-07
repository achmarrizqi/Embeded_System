#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ZTE_2.4G_TuYTR4";
const char* password = "kasnaman1";

//sesuaikan dengan IP dan path masing-masing server
String serverName = "http://192.168.1.12:1880/flood/node1";
unsigned long lastTime = 0;

// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}
void loop() {
  //Send an HTTP Get request every 5 detik
  float dev_id = 28, level = 5, rainfall = 10.2, flow = 12;
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      String serverPath = serverName + "?dev_id=" + dev_id + "&level=" + level + "&rainfall=" +
                          rainfall + "&flow=" + flow;
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
