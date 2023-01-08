#include <ESP8266WiFi.h>
#include "display.h"
#include "server.h"

// Put your Wi-Fi creds here.
const char* ssid = "";
const char* password = "";

Display display(128, 64, 0x3C);

std::vector<Endpoint> endpoints = {
    Endpoint{"/", [](){display.showMessage("TEST", 3); return "<h1>Hello!</h1>";}},
};

void setup() {
    Serial.begin(115200);
    Serial.println("/n");

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());

    display.showMessage(WiFi.localIP().toString().c_str(), 1);
}

void loop() {
    static EspServer server(80, endpoints);
    server.handleClient();
}
