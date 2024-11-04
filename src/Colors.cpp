#include "../include/Colors.h"

#include <iostream>
#include <windows.h>


void setConsoleColor(int color) {
    // Use to change console color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
};

Colors::Colors(){
    this->colors;
};

void Colors::setColors() {
    this->colors["blue"] = 1;
    this->colors["green"] = 2;
    this->colors["light blue"] = 3;
    this->colors["red"] = 4;
    this->colors["purple"] = 5;
    this->colors["orange"] = 6;
    this->colors["gray"] = 8;
    this->colors["light green"] = 10;
    this->colors["cyan"] = 11;
    this->colors["white"] = 15;
};

std::map<std::string, int> Colors::getColors(){
    return this->colors;
};

void Colors::removeColor(const std::string& color){
    this->colors.erase(color);
};


void Colors::getColorsInfos() const {
    setConsoleColor(32);
    std::cout << "[INIT] - Here you can see each possible colors : " << std::endl;
    for (int code = 1; code <= 15; ++code) {
        for (const auto& color : colors) {
            if (color.second == code) {
                setConsoleColor(color.second);
                std::cout << "[INIT] - Color : " << color.first << std::endl;
            }
        }
    }
    setConsoleColor(7);
}

Colors::~Colors(){};
