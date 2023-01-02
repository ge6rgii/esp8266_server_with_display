#include <iterator>
#include <Wire.h>
#include "server.h"

EspServer::EspServer(int port, const std::vector<Endpoint>& endpoints) : server(port) {
    server.begin();
    for (const auto& [url, callback] : endpoints) {
        server.on(url, [this, callback](){server.send(200, "text/html", callback().c_str());});
    }
}

void EspServer::handleClient() {
    server.handleClient();
}
