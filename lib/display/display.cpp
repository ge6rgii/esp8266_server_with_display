#include "display.h"
#include <Wire.h>

Display::Display(int width, int height, int i2c) {
    screen_width = width;
    screen_height = height;
    i2c_addr = i2c;
    display = Adafruit_SSD1306(screen_width, screen_height, &Wire, -1);
    displaySetup();
};

void Display::displaySetup() {
    if(!display.begin(SSD1306_SWITCHCAPVCC, i2c_addr)) { 
        Serial.println("SSD1306 allocation failed");
        for(;;); // Don't proceed, loop forever
    }
    delay(500);
};

void Display::showMessage(const char* text, int font_size) {
    int16_t x, y;
    uint16_t width, height;

    display.setTextSize(font_size);
    display.getTextBounds(text, 0, 0, &x, &y, &width, &height);

    // display on horizontal and vertical center
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor((screen_width - width) / 2, (screen_height - height) / 2);
    display.println(text);
    display.display();
};
