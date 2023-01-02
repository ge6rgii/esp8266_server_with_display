// TODO: pragma
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_SSD1306.h>

class Display { 
    public:
        Display(int width, int height);
        void showMessage(const char* text, uint8_t font_size);

    private:
        Adafruit_SSD1306 display;
        int screen_width;
        int screen_height;
        void displaySetup();
};

#endif
