#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// Update these with values suitable for your network.
const char* ssid = "ZTE_2.4G_TuYTR4";
const char* password = "kasnaman1";
const char* mqtt_server = "broker.emqx.io";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  char payload[200];
  /* for JSON6
    StaticJsonBuffer<200> doc;
    doc["dev_id"] = 28;
    doc["level"] = 25;
    doc["rainfall"] = 5.25;
    doc["flow"] = 10;
    serializeJson(doc, payload); */
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& doc = jsonBuffer.createObject();
  doc["dev_id"] = 28;
  doc["level"] = 25;
  doc["rainfall"] = 5.25;
  doc["flow"] = 10;
  doc.printTo(payload);
  client.publish("flood/node1", payload);
  delay(10000);
}
