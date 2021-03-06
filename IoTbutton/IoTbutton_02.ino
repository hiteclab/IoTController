/********************************************************

IoTbutton V0.2
Check the state of a button conected to an ESP8266 v01 from a website with PHP.
Visualizar el estado de un botón conectado a un ESP8266 v01 desde un sitio web con PHP.
https://github.com/hiteclab/IoTController

*********************************************************
ENGLISH
*********************************************************

Developed by Jose David Cuartas
Hypermedia Lab of Technologies for Communication
University Los Libertadores
Bogotá, Colombia, 2016.
GPL license V3

This code is based in the example: "BasicHTTPClient.ino"
For the ESP8266 Arduino library (https://github.com/esp8266/Arduino) 
created by Ivan Grokhotkov on: 24.05.2015

***********************************************************
ESPAÑOL
***********************************************************

Desarrollado por Jose David Cuartas Correa
Laboratorio Hipermedia de Tecnologias para Comunicación
Fundación Universitaria Los Libertadores
Bogotá, Colombia, 2016.
Licencia GPL Versión 3 

Este código se basa en el ejemplo: "BasicHTTPClient.ino" 
Para la Librería ESP8266 de Arduino (https://github.com/esp8266/Arduino)
desarrollada por Ivan Grokhotkov en: 24.05.2015

********************************************************/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define SERIAL Serial

ESP8266WiFiMulti WiFiAccess;


void setup() {

    SERIAL.begin(115200);

    for(uint8_t t = 4; t > 0; t--) {
        SERIAL.printf("WAIT: %d\n", t);
        SERIAL.flush();
        delay(1000);
    }

    WiFiAccess.addAP("SSID", "PASSWORD"); //CHANGE HERE!

      pinMode(2, INPUT);

}

void loop() {
  
    // wait for WiFi connection
    if((WiFiAccess.run() == WL_CONNECTED)) {

        HTTPClient http;

        // Read state Pin GPIO2
        if(digitalRead(2)==LOW){
            http.begin("http://YourServerURL/index.php?state=ON"); //CHANGE HERE!
            SERIAL.println("Pressed");
        } else {
            http.begin("http://192.168.1.101/php/IoTbutton/index.php?state=OFF"); //HTTP
            SERIAL.println("Released");
        }
        
        // start connection and send HTTP header
        int httpCode = http.GET();
        http.end();
  
    }

delay(500);
}
