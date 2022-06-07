/*
 * source file used to test BME library creation
 * with C++
 */

#include <Adafruit_BME280.h>
#include "BME280.h"
#include "constants.h"

// declare instance of bme sensor
Adafruit_BME280 bme;

// initialize instance of BME for serial output display
BME::BME(int BMEaddr) {
    if (!bme.begin(BMEaddr)) {
        Serial.println("Could not find a valid BME280 sensor, check wiring or default address!");
        while (1);  
    }
}

void BME::printBMEToSerial() {

    // define bme readings as float vals
    // convert bme celsius reading to fahrenheit 
    float _temp = bme.readTemperature() * 9/5 + 32;
    float _hum = bme.readHumidity();
    // convert bme pascals reading to hectropascals
    float _press = bme.readPressure() / 100.0;
    // convert pressure to height in feet
    float _alt = bme.readAltitude(SEALEVELPRESSURE_HPA) * 3.281;
    
    Serial.println("From BME280 Sensor: ");
    // print values to serial
    Serial.print("Temperature: ");
    Serial.print(_temp);
    Serial.println(" *F");
    
    Serial.print("Humidity: ");
    Serial.print(_hum);
    Serial.println(" %");
    
    Serial.print("Pressure: ");
    Serial.print(_press);
    Serial.println(" hPa");

    Serial.print("Altitude: ");
    Serial.print(_alt);
    Serial.println(" ft");

    Serial.println();
    delay(5000);
}
