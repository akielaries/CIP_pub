/*
   plan to use this as main file and calling headers
   to carry out the task
*/
#include <Arduino.h>
#include "BME280.h"
#include "displayLCD.h"
//#include "DS18B20.h"

#define VERSION 3

// initialize different peripherals here
void setup() {
    // set baud rate
    Serial.begin(9600);
  
    LCD a(0x27, 16, 02);
    a.initializeLCD();
}

// loop thru given functions to display sensor vals
void loop() {  
    // printToLCD function for our sensors  
    LCD a(0x27, 16, 02);
    a.main();
    
    // declare BME sensors I2C address and call theprintToSerial function
    BME b(0x77);
    b.printBMEToSerial();
  
    // printToSerial function for DS18B20 sensor
   
    delay(1000);
  
}
