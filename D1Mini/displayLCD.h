/*
* header file for corresponding .cpp file to 
* display sensor values to connect LCD screen
*/

#ifndef displayLCD_h
#define displayLCD_h

class LCD {
    public:
        LCD(int addr, int width, int height);        
        void initializeLCD();
        void main();
        void displayTemp();
        void displayPressure();
        void displayAltitude();
        void displayHumidity();
};

#endif
