#include "../include/Colors.h"

#include <iostream>
#include <windows.h>
#include <map>
#include <algorithm>
#include <stdexcept>


void setConsoleColor(int color) {
    // Use to change console color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
};

Colors::Colors(){
    setColors();
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

int Colors::getColorCode(const std::string& colorName) const {
    // Use to get color's code by user color string
    std::string colorLower = colorName;

    // Convert to be not case-sensitive
    std::transform(colorLower.begin(), colorLower.end(), colorLower.begin(), ::tolower);

    auto it = colors.find(colorLower);
    if ( colorName != "colors") {
        if (it != colors.end()) {
            return it->second;
        } else {
            setConsoleColor(79);
            std::cout << "[ERROR] - Invalid color";
            setConsoleColor(7);
            std::cout << std::endl;
            return 0;
        }
    } else {
        return 0;
    }
}

void Colors::removeColor(const std::string& color){
    this->colors.erase(color);
};


void Colors::getColorsInfos() const {
    setConsoleColor(32);
    std::cout << "[INIT] - Here you can see each possible colors : ";
    setConsoleColor(7);
    std::cout << std::endl; // In order to not get next line with color and background

    for (int code = 0; code <= 15; ++code) {
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
