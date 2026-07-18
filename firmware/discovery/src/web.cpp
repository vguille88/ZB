#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

AsyncWebServer server(80);

void startWeb()
{

server.serveStatic("/",LittleFS,"/").setDefaultFile("index.html");

server.on("/api/info",HTTP_GET,[](AsyncWebServerRequest *request){

JsonDocument doc;

doc["chip"]="ESP32";

doc["cores"]=ESP.getChipCores();

doc["revision"]=ESP.getChipRevision();

doc["flash"]=ESP.getFlashChipSize()/1024/1024;

doc["sdk"]=ESP.getSdkVersion();

String out;

serializeJson(doc,out);

request->send(200,"application/json",out);

});

server.begin();

}