#include <Arduino.h>
#include <WiFi.h>
#include <LittleFS.h>

void startWeb();

const char* ssid="TU_WIFI";
const char* password="TU_PASSWORD";

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid,password);

    while(WiFi.status()!=WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println(WiFi.localIP());

    if(!LittleFS.begin(true))
    {
        Serial.println("LittleFS error");
    }

    startWeb();
}

void loop()
{
}