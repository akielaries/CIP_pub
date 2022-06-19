FROM ubuntu:latest

# install updates and install cron and apt-utils
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install cron
RUN apt-get install apt-utils

# install dependencies
# influxdb
RUN apt-get install influxdb
RUN apt-get install influxdb-client
RUN service influxdb start
# py utils
RUN apt-get install -y python3 python3-distutils python3-pip python3-apt
# install paho-mqtt and influxDB via pip for py libs
RUN pip3 install paho-mqtt
RUN pip3 install influxdb

# add crontab and grant execution rights
ADD crontab /crontab
RUN chmod 0644 /crontab 

# add MQTTInfluxBridge.py program and grant execution rights
ADD /mqtt/MQTTInfluxBridge.py /mqtt/MQTTInfluxBridge.py
RUN chmod +x /mqtt/MQTTInfluxBridge.py

# create log file to able to run tail
RUN touch /home/pi/Work/IoT/climate_indicator/logs/cron.log 

# print csv header before cron starts up
#CMD echo "#date-time,temp,pres,hum" && cron && tail -f /var/log/cron.log
# note this version appends to file /data/bme280-test1.csv (see script.sh)
#CMD echo "#date-time,temp,pres,hum" && cron && tail -f /data/bme280-test1.csv
#CMD echo "#date-time,temp,pres,hum" >> /data/bme280-test1.csv && while true;do sleep 1;done

# run cmd on container startup
CMD cron && tail -f /home/pi/Work/IoT/climate_indicator/logs/


