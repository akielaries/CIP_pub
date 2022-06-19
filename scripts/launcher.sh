#!/bin/sh
# launcher.sh runs the MQTTInfluxDB.py file on startup of
# MQTT subrciber

# ----- Will later impliment Docker Container for this -----

# pause 60 secs
sleep 60

python3 /home/pi/IoT/climate_indicator/mqtt/MQTTInfluxBridge.py


