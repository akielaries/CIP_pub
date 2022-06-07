Repository for Climate Indicator Project done for the Northern
Arizona University Internet of Things & School of Informatics,
Computing, and Cyber Systems [DISCOVER CCRI research project](https://discoverccri.org/). 

Authors
[Akiel Aries](https://akielaries.github.io/)

# Introduction
This repository contains code that transmits values read 
from these sensors :

- BME280 Temperature Humidity Pressure Sensor
- DS18B20 Liquid Sensor
- SHT30 Temperature and Humidity sensor **(*redundant*)**

over MQTT through an ESP module located on a D1 Mini pro 
dev board to a database hosted on an RPI 4.

## Repo Details
#### ATMEGA2560
Folder contains modularized code for reading values in 
from the BME280 and displaying them both to Serial and 
an LCD attached. 

#### D1Mini
Folder contains a rough sketch on sending values read 
from the BME280 and publishing the data through the ESP 
module located on the D1 mini dev board via MQTT. The 
data is then sent into an instance of InfluxDB hosted on 
a Raspberry Pi 4. 

#### MQTT

#### Schematic Coming Soon...
#### *Todo:*

#### End goal of this project
Idea is to use the ATMEGA2560 as a host microcontroller 
and utilize an ESP module (D1 Mini Pro, or bare ESP82066 
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

# Build 
*Explain how to build this project. Want this to be
executed with running docker only*

Clone the repository and build from the Dockerimage:

    $ cd climate_indicator_proj
    $ docker build --rm -t climate_indicator_proj .  
*Todo:*


# How to Contribute to this project...
#### *Todo:*
