Repository for Climate Indicator Node done for the Northern Arizona University Internet of Things (IoT) team.

Authors
[Akiel Aries](https://www.github.com/aba275)


# Introduction
This repository contains code that transmits values read
from various sensors and published them via MQTT to an Instance of
InfluxDB hosted on an RPI 4 with additional peripherals to be added.

- BME280 Temp, Hum., Press.
- DS18B20 Liquid Sensor     (can be used for measuring ground temp)
- ~~SHT30 Temp & Hum.~~     **(*redundant but maybe good for veryfing other peripheral readings*)**
    - Using SHT30 (x2) for testing communication over I2C vs SCI

Additional peripherals will include :

- CO2 & Air Quality Sensor (CCS811 CO2 & Air Qual)
- Adafruit Anemometer 
- Host MCU & BME280 w/ STEMM QT soil sensor

## Repo Details
#### ATMEGA2560
Folder contains modularized code for reading values in
from the BME280 and displaying them both to Serial and
an LCD attached.

#### D1Mini
##### *(MQTT publish code currently decoupled from main())*
Folder contains a rough sketch on sending values read
from the BME280 and publishing the data through the ESP
module located on the D1 mini dev board via MQTT. The
data is then sent into an instance of InfluxDB hosted on
a Raspberry Pi 4.

#### MQTT
Folder contains rough sketch of how values will be
transmitted from the host microcontroller(D1 Mini Pro)
to the raspberry pi that will store these values.


#### Schematic 
![CIP_schematic_v0 with KiCad](https://github.com/akielaries/CIP_pub/blob/main/img/KICAD_CIP_SCHEMATIC_V0.png)


#### End goal of this project
Idea is to use the ATMEGA32U4 (W/ Atheros AR9331 chip) as a host 
microcontroller connected to various peripherals to read and publishing values. 
The values will be published via MQTT and fed into an instance of InfluxDB hosted 
on a RPI 4. The data can be visualized in a number of way (will likely go with 
grafana at first). The mass amounts of readings sent into the DB are subject to statistical analysis in 
this case the implementation of the Python lib Pandas will be used, also for the visual implementation stage...
Final result will contain necessary peripherals on a Printed Circuit Board (PCB).

# Dependencies
#### *Todo*

# Build
*Explain how to build this project. Want this to be
executed with running docker only*

Clone the repository and build from the Dockerimage:

    $ cd climate_indicator_proj
    $ docker build --rm -t climate_indicator_proj .
*Todo:*


# How to Contribute to this project...
#### *Todo:*

### Potential & Forseeable complications with future implementations
- Using the Arduino C/C++ code and lackluster IDE uses more memory
than bare metal C alongside AVR-GCC compiler or ESP equivalent.
- With recent discovery of Arduino Yun Rev 2 (ATMEGA32u4 chip alongside
a Atheros AR9331 with ethernet & wireless capabilities) this could eliminate
needing to use the underpowered D1 Mini Pro as a host device or needing to siphon off
connections for wireless on more suitable device like the ATMEGA2560.
    - will use the D1 as a voltage reader of the project and publish those values as a
    seperate MQTT topic.
- can use the beaglebone as a subscriber device to host values like the RPI 

