//full code for node mcu 
//bien bool bao hieu co chay
bool cochay=false;
//wifi blynk connection
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

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
while(!Serial){
  ;
} 
}
int machay;
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  Serial.write(Serial.read());
  // blynk logevent- co tin hieu tu arduino uno tuc la co dam chay 
  cochay=true;
}
delay(1000);

//chay blynk
Blynk.run();
if(cochay==true){
  Blynk.logEvent("fire_noti","FIRE!FIRE! ");
  delay(100000);
}
delay(2000);

}
