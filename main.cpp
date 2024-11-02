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

void startGameName() {
    setConsoleColor(14);
    cout << ">>==========================================================<<" <<endl;
    cout << "||                                                          ||" <<endl;
    cout << "|| _    ____ _   _ _ _  _ ____    ____ ____ ____ ____ ____  ||" <<endl;
    cout << "|| |    |__|  \\_/  | |\\ | | __    | __ |__/ |__| [__  [__   ||" <<endl;
    cout << "|| |___ |  |   |   | | \\| |__]    |__] |  \\ |  | ___] ___]  ||" <<endl;
    cout << "||                        Console Game                      ||" <<endl;
    cout << "||                                                          ||" <<endl;
    cout << ">>==========================================================<<" <<endl;
    setConsoleColor(7);
}

int main()
{
    startGameName();
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
