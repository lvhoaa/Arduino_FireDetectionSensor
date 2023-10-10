
#include <ESP8266WiFi.h>
#define BLYNK_TEMPLATE_ID "TMPL7GN56hG8"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "gOV41gRx0N4bFomrLFtX0YKl4lKRHmYr"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>

char auth[] = "gOV41gRx0N4bFomrLFtX0YKl4lKRHmYr";

// Your WiFi credentials.- connect to wifi

// Set password to "" for open networks.
char ssid[] = "Panda";
char pass[] = "567ef432";

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
}

//void thongbao(string tinnhan){
  //Blynk.logEvent("fire_noti",tinnhan)
//}

void loop()
{
  Blynk.run();
  Blynk.logEvent("fire_noti","FIRE!FIRE! ");
  delay(10000);
}
