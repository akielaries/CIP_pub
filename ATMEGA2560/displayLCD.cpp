/*
 * source files testing displaying sensor values to
 * connect LCD screen using C++
*/ 
#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <LiquidCrystal_I2C.h>
#include "BME280.h"
#include "displayLCD.h"

#define SEALEVELPRESSURE_HPA (1013.25)

// define instance of BME in this file
Adafruit_BME280 bme2;
// define instance of LCD in this file
LiquidCrystal_I2C lcd(0x27, 16, 02);

// initialize LCD screen with I2C address and dimensions 16x02
LCD::LCD(int addr, int width, int height) {
    LiquidCrystal_I2C lcd(addr, width, height);       
}

// display to LCD screen using infinite while loop to constantly
// iterate through the called methods
void LCD::main() {
    while(1){      
        displayTemp();
        displayPressure();
        delay(5000);
        lcd.clear();
        
        displayAltitude();
        displayHumidity();
        delay(5000);
        lcd.clear();
    }
}

// initialize the LCD by blinking and leaving backlight on for
// values to display
void LCD::initializeLCD() {
    lcd.init();
    bme2.begin();
    for (int i = 0; i < 1; i++) {
        lcd.backlight();
        delay(150);
        lcd.noBacklight();
        delay(150);
    }
    lcd.backlight();
}

void LCD::displayTemp() {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print((bme2.readTemperature() * 9 / 5) + 32);
    lcd.print(" F");
}

void LCD::displayPressure() {
    lcd.setCursor(0, 1);
    lcd.print("Press: ");
    lcd.print(bme2.readPressure() / 100.0F);
    lcd.print("hPa");
}

void LCD::displayAltitude() {
    lcd.setCursor(0, 0);
    lcd.print("Alt: ");
    lcd.print(bme2.readAltitude(SEALEVELPRESSURE_HPA) * 3.281);
    lcd.print(" ft");
}

void LCD::displayHumidity() {
    lcd.setCursor(0, 1);
    lcd.print("RH: ");
    lcd.print(bme2.readHumidity());
    lcd.print("%");
}
