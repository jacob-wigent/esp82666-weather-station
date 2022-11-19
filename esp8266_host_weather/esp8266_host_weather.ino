#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


#include "index.h" //HTML webpage contents

#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 5

//SSID and Password of WiFi router
const char* ssid = "Alcatraz";
const char* password = "Alcatrazdon4130!";

ESP8266WebServer server(80); //Server on port 80
DHT dht(DHTPIN, DHTTYPE);

float temperature;
float humidity;
float heat_index;

float update_interval = 10000;
unsigned long msecLst;

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String html = dashboard_page; //Read HTML contents

 //Only fetch values only x seconds (update_interval)
  unsigned long msec = millis();
    if ((msec - msecLst) > update_interval)  {
        msecLst = msec;
        temperature = (dht.readTemperature()*1.8f) + 32;
        humidity = dht.readHumidity();
        heat_index = dht.computeHeatIndex(temperature, humidity);
    }

 //Fill in values 
 Serial.println(temperature);
 Serial.println(humidity);
 
 html.replace("{temperature}", String(temperature) + "°F");
 html.replace("{humidity}", String(humidity) + "%");
 html.replace("{heat-index}", String(heat_index) + "°F");
 
 server.send(200, "text/html", html); //Send web page
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  delay(100);

  pinMode(DHTPIN, INPUT);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient(); //Handle client requests
}
