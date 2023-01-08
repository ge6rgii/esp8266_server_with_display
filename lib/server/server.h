#pragma once

#include <ESP8266WebServer.h>
#include <string>

struct Endpoint {
    const Uri url;
    std::function<std::string()> callback;
};

class EspServer {
    public:
        EspServer(int port, const std::vector<Endpoint>& endpoints);
        void handleClient();

    private:
        ESP8266WebServer server;
};
