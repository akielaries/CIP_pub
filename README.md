Repository for Climate Indicator Node done for the Northern
Arizona University Internet of Things team & School of Informatics,
Computing, and Cyber Systems [DISCOVER CCRI research project](https://discoverccri.org/)

Authors
[Akiel Aries](https://akielaries.github.io/)

# Introduction
This repository contains code that transmits values read 
from various sensors and published them via MQTT to an Instance of
InfluxDB hosted on an RPI 4 with additional peripherals to be added.

- BME280 Temp, Hum., Press. 
- DS18B20 Liquid Sensor     (can be used for measuring ground temp)
- ~~SHT30 Temp & Hum.~~     **(*redundant but maybe good for veryfing other peripheral readings*)**

Additional peripherals will include :

- CO2 & Air Quality Sensor (CCS811 CO2 & Air Qual)
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


#### Schematic Coming Soon...
#### *Todo:*

#### End goal of this project
Idea is to use the ATMEGA2560 as a host microcontroller 
and utilize an ESP module (D1 Mini Pro, or bare ESP8266 
module) to give the MCU internet connectivity for publishing 
values. The values will be published via MQTT and fed into 
an instance of InfluxDB hosted on a RPI 4. The data can 
be visualized in a number of way (will likely go with 
grafana.) The mass amounts of readings sent into the DB 
are subject to statistical analysis in this case the 
implementation of the Python lib Pandas will be used which
will also be used in the visual implementation stage...
Final result will contain necessary peripherals on a
Printed Circuit Board (PCB).
##### ***if memory usuage becomes an issue in future implementations, utilization of ESP & AVR specific embedded C will be explored***

# Build 
*Explain how to build this project. Want this to be
executed with running docker only*

Clone the repository and build from the Dockerimage:

    $ cd climate_indicator_proj
    $ docker build --rm -t climate_indicator_proj .  
*Todo:*


# How to Contribute to this project...
#### *Todo:*

# Potential & Forseeable complications with future implementations
- Using the D1 Mini Pro as a host MCU has its limits. To provide ideal
power output we will want to couple the existing D1 Mini Pro code w/
the ATMEGA2560 and daisy chain wifi capabilities from that or a bare
ESP8266 module. 
- Using the Arduino psuedo C/C++ code and lackluster IDE uses more memory
than bare metal C alongside AVR-GCC compiler or ESP equivalent.

