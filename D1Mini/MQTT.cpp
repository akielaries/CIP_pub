/*
 * source file used to test MQTT data transmission
 * with C++
 */

#include <ESP8266WiFi.h>
#include "PubSubClient.h"
#include "MQTT.h"
#include "constants.h"

// initialize wifi and mqtt objects
WiFiClient wifiClient;

// 1883 is being used as listener port
PubSubClient client(mqtt_server, 1883, wifiClient);

// function to connect to mqtt broker via wifi and return error messages
void connect_MQTT() {
    Serial.print("Connecting to: ");  
    Serial.println(ssid);
    // connect to wifi network using defined variables 
    /******* IMPLEMENT API FOR CREDENTIALS IN LATER VERSION *******/
    WiFi.begin(ssid, WPA2);
    
    // wait for connection confirmation before continuing
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      
    // for debugging purposes, print IP of ESP8266 module
    Serial.println("WiFi Connected!");
    Serial.print("IP Addr of ESP2866 module: ");
    Serial.println(WiFi.localIP());
    
    // connect to MQTT broker and print connection succes or failure
    if (client.connect(clientID, mqtt_user, mqtt_pass)) {
        Serial.println("**** Connected to MQTT Broker ****");
    }
    
    else {
      Serial.println("Connection failed!");    
    }
  
}
