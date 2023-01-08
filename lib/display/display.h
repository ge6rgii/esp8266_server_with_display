#pragma once

#include <Adafruit_SSD1306.h>

class Display {
    public:
        Display(int width, int height, int i2c);
        void showMessage(const char* text, int font_size);

    private:
        int screen_width;
        int screen_height;
        int i2c_addr;
        Adafruit_SSD1306 display;
        void displaySetup();
};
