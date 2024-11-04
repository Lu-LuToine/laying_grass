#include "../include/Colors.h"

#include <iostream>
#include <windows.h>


void setConsoleColor(int color) {
    // Use to change console color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
};

//TODO dico marche pas
Colors::Colors(){
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

Colors::~Colors(){};

std::map<char, int> Colors::getColors(){
    return this->colors;
};

std::map<char, int> Colors::removeColor(int color){
    this->colors.erase(color);
};