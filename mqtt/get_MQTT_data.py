"""
py script setting up subscribe portion of MQTT process for
climate indicator project. view details on project elsewhere. 
"""

import paho.mqtt.client as mqtt

MQTT_ADDRESS = '111.111.1.11'
MQTT_USER = '*****'
MQTT_PASSWORD = '*****'
MQTT_TOPIC = 'home/+/+'

def on_connect(client, userdata, flags, rc):
    """ 
    callback for when client recieves CONNACK RESPONSE FROM THE SERVER
    """
    print('Connected with result code' + str(rc))
    client.subscribe(MQTT_TOPIC)

def on_message(client, userdata, msg):
    """
    callback for when a publish message is received from server
    """
    print(msg.topic + '' + str(msg.payload))

def main():
    mqtt_client = mqtt.Client()
    mqtt_client.username_pw_set(MQTT_USER, MQTT_PASSWORD)
    mqtt_client.on_connect = on_connect
    mqtt_client.on_message = on_message
    
    mqtt_client.connect(MQTT_ADDRESS, 1883)
    mqtt_client.loop_forever()

if __name__ == '__main__':
    print('MQTT to DB bridge')
    main()

