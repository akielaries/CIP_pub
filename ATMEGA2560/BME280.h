/*
 * library created to test library usage with arduino 
 * BME280 sensor
 */
#ifndef BME280_h
#define BME280_h

#include <Arduino.h>

class BME {
    public:
        BME(int BMEaddr);
        BME2(int BMEaddr);
        void printBMEToSerial();
};

#endif
