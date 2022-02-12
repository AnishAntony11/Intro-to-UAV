//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "B603"  // Add your network credentials
#define STAPSK  "csplab123"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
 
}

//-------------------------------------------------------//
int LED = 5;
void setup(){
  OTAsetup();

//-------------------//
  // Custom setup code //
  //-------------------//
pinMode(LED, OUTPUT);
}

void loop() {
  OTAloop();
  digitalWrite(LED, HIGH); // turn the LED on
  delay(1000); // wait for a second
  digitalWrite(LED, LOW); // turn the LED off
  delay(1000); // wait for a second

}
