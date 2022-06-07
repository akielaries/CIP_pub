/*
   plan to use this as main file and calling headers
   to carry out the task
*/

#include "BME280.h"
#include "displayLCD.h"
#include "constants.h"

//#include "DS18B20.h"

#define VERSION 4
// define LCD with I2C addr and dimension
LCD a(0x27, 16, 02);
BME b(0x77);

// initialize different peripherals here
void setup() {
    // set baud rate
    Serial.begin(9600);
  
    a.initializeLCD();

    /*  for LED visual error checking initialize
     *  - RED
     *  - YELLOW
     *  - BLUE
     *  - GREEN 
     *  HIGH = ON
     *  LOW = OFF
     */
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    
}

// loop thru given functions to display sensor vals
void loop() {  
    // printToLCD function for our sensors  
    //LCD a(0x27, 16, 02);
    a.main();
    Serial.println("De-Bug");
    // declare BME sensors I2C address and call theprintToSerial function
    //BME b(0x77);
    b.printBMEToSerial();
    
    // printToSerial function for DS18B20 sensor
   
    delay(1000);
  
}
