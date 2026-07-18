#include <Arduino.h>
#include <WebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

#include "web.h"

WebServer server(80);

void handleInfo()
{
    JsonDocument doc;

    doc["chip"] = ESP.getChipModel();
    doc["cores"] = ESP.getChipCores();
    doc["revision"] = ESP.getChipRevision();
    doc["flash_mb"] = ESP.getFlashChipSize() / 1024 / 1024;
    doc["sdk"] = ESP.getSdkVersion();
    doc["free_heap"] = ESP.getFreeHeap();
    doc["wifi_rssi"] = WiFi.RSSI();

    String output;

    serializeJson(doc, output);

    server.send(200, "application/json", output);
}

void startWeb()
{
    server.serveStatic("/", LittleFS, "/", "max-age=600")
          .setDefaultFile("index.html");

    server.on("/api/info", HTTP_GET, handleInfo);

    server.begin();

    Serial.println("Servidor web iniciado");
}

void handleWeb()
{
    server.handleClient();
}