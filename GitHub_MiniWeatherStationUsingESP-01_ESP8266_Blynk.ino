/*Mini Weather Station using ESP-01 (ESP8266) and monitored by Blynk Android App*/
/* This example shows how temperature and humidity values can be pushed from Arduino to the Blynk App.
 * Install:
 * Adafruit DHT sensor library:
 * https://github.com/adafruit/DHT-sensor-library
 *
 * Blynk App Mini Weather Station project setup:
 *   Temperature Value display widget attached to V6
 *   Humidity Value display widget attached to V5
 ***************************************************************************************************/
#include <Blynk.h>
#define BLYNK_PRINT Serial         // Comment this out to disable prints and save space
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

/*Retrieve Auth Token from Blynk App. Check your registed email for the Auth Token*/
char auth[] = "          ";      //Enter the Auth code. Example:tmo1PmzkSMcKI9wjy2eN8vt-5qBNqApe

/*Your WiFi credentials*/
// Set password to "" for open networks.
char ssid[] = "Your-WIFI";                  //Enter your WIFI Name
char pass[] = "WIFI Password";                 //Enter your WIFI Password

#define DHTPIN 2                            // Digital pin 2 (ESP-01 module)


/* define your DHT device that you are using. Comment (//) the others*/
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;     

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}
void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}

/*************************************************************************
 Ed_Cañeda references:
 Viral Science Youtube: https://www.youtube.com/watch?v=WLFUwyyPrKo
           Sketch/code: https://www.viralsciencecreativity.com/post/blynk-esp8266-dht11-temperature-sensor

   ICStation ESP DHT11: https://www.youtube.com/watch?v=4BCJyZn8v4k by Csongor Varga
           Sketch/Code: https://learn.adafruit.com/esp8266-temperature-slash-humidity-webserver/code

            Rui Santos: https://www.youtube.com/watch?v=hXhYLd4O8cU&feature=youtu.be
 Random Nerd Tutorials: https://randomnerdtutorials.com/esp8266-dht11dht22-temperature-and-humidity-web-server-with-arduino-ide/
           
         
 */
