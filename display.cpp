#include <Wire.h>
#include <Adafruit_GFX.h>
#include "display.h"

Display::Display(int width, int height)
    : screen_width(width), screen_height(height), display (Adafruit_SSD1306(screen_width, screen_height, &Wire, -1))
    {
        displaySetup();
    }

void Display::showMessage(const char *text, uint8_t font_size = 1) {
    int16_t x1, y1;
    uint16_t width, height;

    display.setTextSize(font_size);
    display.getTextBounds(text, screen_width, screen_height, &x1, &y1, &width, &height);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor((screen_width - width) / 2, (screen_height - height) / 2);
    display.println(text);
    display.display();
}

void Display::displaySetup() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        for (;;);
    }
    delay(500);
}
