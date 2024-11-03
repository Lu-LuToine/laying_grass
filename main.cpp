#include "include/Player.h"
#include "include/board/Board.h"
#include "include/colors.h"
#include "include/menu.h"

#include <iostream>

using namespace std;

const int Player_number = 2;
Player Player[Player_number];


int main()
{
    startGameMenu();

    Board Board1;
    Board1.setSize(5);
    cout << Board1.getSize() << endl;
    Board1.setBoard();
    Board1.getBoard();

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
    system("pause");
    return 0;
}
