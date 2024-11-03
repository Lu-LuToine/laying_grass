#include "../include/colors.h"

#include <iostream>
#include <windows.h>


void setConsoleColor(int color) {
    // Use to change console color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}