#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "speedy";
const char* password = "Cek12345";

ESP8266WebServer server(80);

void homePage() {
  server.send(200, "text/plain", "Hello from ESP8266");
}

void testPage() {
  String json = "{\"message\": \"Success\", \"statusCode\": 200}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", homePage);
  server.on("/test", testPage);
  server.begin();
}

void loop() {
  server.handleClient();
}
