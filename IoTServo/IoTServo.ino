/********************************************************

IMPORTANT!!!!!!! THE SERVO HAVE TO BE CONECTED AFTER PUT ON THE ESP OTHERWISE WILL NOT WORK

IMPORTANTE!!!!!! EL SERVO TIENE QUE SER CONECTADO DESPUES DE PRENDER EL ESP DE LO CONTRARIO NO FUNCIONA

IoTServo V0.1
Control a Servo with the ESP8266 v01 from a website with PHP.
Controle un servo con un ESP8266 v01 desde un sitio web con PHP.
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


#include <Servo.h> 

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define SERIAL Serial


ESP8266WiFiMulti WiFiAccess;
Servo myservo;  // create servo object to control a servo 
int valor=-1;


void setup() {

    SERIAL.begin(115200);

    for(uint8_t t = 4; t > 0; t--) {
        SERIAL.printf("WAIT: %d\n", t);
        SERIAL.flush();
        delay(1000);
    }

    WiFiAccess.addAP("SSID", "PASSWORD"); //CHANGE HERE!


    myservo.attach(2);  // attaches the servo on GIO2 to the servo object 

}

void loop() {
    // wait for WiFi connection
    if((WiFiAccess.run() == WL_CONNECTED)) {

        HTTPClient http;        
        http.begin("http://YourServerURL/valor.txt"); //CHANGE HERE!

        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String data = http.getString();
                valor = data.toInt();
                SERIAL.println(valor);
            }
        } else {
            SERIAL.printf("Error");
        }
        http.end();
    }

    if(valor>-1) myservo.write(valor);              // tell servo to go to position in variable 'valor' 
    delay(1000);                       // waits 1s for the servo to reach the position 
}
