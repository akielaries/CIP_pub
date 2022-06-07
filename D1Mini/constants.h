/*
 * constants that will be used through this program
 */
// define WiFi credentials
#define ssid "SSID"
#define WPA2 "WPA2"

// MQTT credentials
#define mqtt_server "111.111.1.11"      // MQTT broker IP (RPI 4 in this instance)
#define mqtt_user "USER"
#define mqtt_pass "PASS"
#define clientID "client_area"

// MQTT topics
#define temp_topic "home/area/BME_temp"
#define hum_topic "home/area/BME_hum"
#define press_topic "home/area/BME_press"
#define alt_topic "home/area/BME_press"

// BME280 Sealevel Pressure
#define SEALEVELPRESSURE_HPA (1013.25)
