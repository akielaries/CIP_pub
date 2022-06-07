/*
 * source file used to test BME library creation
 * with C++
 */
#include <Arduino.h>
#include <Adafruit_BME280.h>
#include "BME280.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

// initialize instance of BME for serial output display
BME::BME(int BMEaddr) {
    if (!bme.begin(BMEaddr)) {
        Serial.println("Could not find a valid BME280 sensor, check wiring or default address!");
        while (1);  
    }
}

void BME::printBMEToSerial() {
    Serial.println("From BME280 Sensor: ");
    // display temperature in celsius and fahrenheit
    Serial.print("Temperature = ");
    Serial.print((bme.readTemperature() * 9/5) + 32);
    Serial.print("*F(");
    Serial.print(bme.readTemperature());
    Serial.println("*C)");

    // display pressure in Hectopascals
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println("hPa");
    
    // display altitude in ft calculated from sealevel pressure
    Serial.print("Approximate Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA) * 3.281);
    Serial.println("ft");
    
    // display relative humidity in %
    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println("%");
    
    // 10 second interval before displaying next round
    // of readings
    Serial.println();
    delay(5000);
}
