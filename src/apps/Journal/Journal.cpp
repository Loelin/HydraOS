//
// Created by Loelin on 06-08-24
//
#include "App.h"
#include "AppManager.h"
#include "M5Cardputer.h"
#include "ScreenManager.h"
#include <string>
#include "SD.h"
#include "Utils.h"
#include "icon.h"

class Journal : public App {
private:
    std::vector<String> history;
    std::vector<String> textbuf;
    fs::SDFS makefile ;



public:
    const char *getName() override { return "Journal"; }
    unsigned char buff[16];
    unsigned char tempfile;



    void onAppOpen() override {
        canvas.fillScreen(BLACK);
        StatusBar::draw(true);
        char tempfile = makefile.begin();

    }

    void onAppClose() override {
    }

    void onAppTick() override {
        Utils::initCanvas();
        String input = "";
        canvas.fillScreen(BLACK);
        canvas.setTextSize(1);
        canvas.setTextColor(GREEN);

        for (int i = 0; i < 8 && i < history.size(); i++) {
            canvas.setCursor(7, 30 + (7 - i) * 8);
            canvas.print(history[history.size() - i - 1]);
        }
        canvas.setCursor(7, 107);
        canvas.setCursor(7, 117);
        canvas.pushSprite(0, 0);
        Utils::waitForInput(input);

    }
void openTextFile(){
std::vector<String> filepath;
makefile.readRAW(buff);
makefile.open(filepath);

    
};
    void draw() override {
    }

    int err;

    const uint8_t *getIcon() override {
        return journal_icon;
    }

    int getIconSize() override {
        return sizeof journal_icon;
    }
};

