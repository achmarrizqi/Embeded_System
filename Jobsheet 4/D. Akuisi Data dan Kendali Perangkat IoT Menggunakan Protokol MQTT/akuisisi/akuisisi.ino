#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

/* change it with your ssid-password */
const char* ssid = "ZTE_2.4G_TuYTR4";
const char* password = "kasnaman1";

/* this is the IP of PC/raspberry where you installed MQTT Server
  on Wins use "ipconfig"
  on Linux use "ifconfig" to get its IP address */
const char* mqtt_server = "broker.emqx.io";
float temperature = 0;

/* create an instance of PubSubClient client */
WiFiClient espClient;
PubSubClient client(espClient);

/*LED GPIO pin*/
const char led = 2;

/* topics */
#define TEMP_TOPIC "flood/node2"
#define LED_TOPIC "flood/node2/led" /* true=on, false=off */
long lastMsg = 0;
char msg[20];
void receivedCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received: ");
  Serial.println(topic);
  Serial.print("payload: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  /* we got '1' -> on */
  if ((char)payload[0] == 't') {
    digitalWrite(led, HIGH);
  } else {
    /* we got '0' -> on */
    digitalWrite(led, LOW);
  }
}
void mqttconnect() {
  /* Loop until reconnected */
  while (!client.connected()) {
    Serial.print("MQTT connecting ...");
    /* client ID */
    String clientId = "ESP32Client";
    /* connect now */
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      /* subscribe topic with default QoS 0*/
      client.subscribe(LED_TOPIC);
    } else {
      Serial.print("failed, status code =");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      /* Wait 5 seconds before retrying */
      delay(5000);
    }
  }
}
void setup() {
  Serial.begin(115200);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  /* set led as output to control led on-off */
  pinMode(led, OUTPUT);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  /* configure the MQTT server with IPaddress and port */
  client.setServer(mqtt_server, 1883);
  /* this receivedCallback function will be invoked
    when client received subscribed topic */
  client.setCallback(receivedCallback);
}
void loop() {
  /* if client was disconnected then try to reconnect again */
  if (!client.connected()) {
    mqttconnect();
  }
  /* this function will listen for incomming
    subscribed topic-process-invoke receivedCallback */
  client.loop();
  /* we measure temperature every 3 secs
    we count until 3 secs reached to avoid blocking program if using delay()*/
  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    char payload[200];
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& doc = jsonBuffer.createObject();
    doc["dev_id"] = 28;
    doc["level"] = 25;
    doc["rainfall"] = 5.25;
    doc["flow"] = 10;
    doc.printTo(payload);
    /* publish the message */
    client.publish(TEMP_TOPIC, payload);
  }
}
