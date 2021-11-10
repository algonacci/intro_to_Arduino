#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "XDh9aoRPfRfoJ2xHSdIxhaj7r9k8irG1";

char ssid[] = "UFO";
char pass[] = "rudi9191";

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, "blynk-cloud.com",8080);
}

void loop()
{
  Blynk.run();
}
