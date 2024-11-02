#include "include/Player.h"

#include <iostream>
#include <windows.h>

using namespace std;

const int Player_number = 2;
Player Player[Player_number];


void setConsoleColor(int color) {
    // Use to change console color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


int main()
{
    // [DEBUG] => check PLAYER and colors
    for (int i = 0; i < Player_number; i++) {
        if (i == 1) {
            Player[i].setName("Jean michel");
            Player[i].setColor(2);
        } else {
            Player[i].setName("Edward");
            Player[i].setColor(3);
        }
        setConsoleColor(Player[i].getColor());
        cout << "Hi i'm " << Player[i].getName() << endl;
        setConsoleColor(7);
    }

    std::cout << "Hello, Worlde!" << std::endl;
    return 0;
}
