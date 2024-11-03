#include "include/Player.h"
#include "include/board/Board.h"
#include "include/colors.h"
#include "include/menu.h"

#include <iostream>

using namespace std;

int main()
{
    int nb_player;

    startGameName();
    startGameMenu();

    cout << "[INIT] - How many Players " << endl;
    cin >> nb_player;

    Player* players = new Player[nb_player]; // Set players



    Board Board1;
    Board1.setSize(5);
    cout << Board1.getSize() << endl;
    Board1.setBoard();
    Board1.getBoard();

    // [DEBUG] => check PLAYER and colors
    for (int i = 0; i < nb_player; i++) {
        if (i == 1) {
            players[i].setName("Jean michel");
            players[i].setColor(2);
        } else {
            players[i].setName("Edward");
            players[i].setColor(3);
        }
        setConsoleColor(players[i].getColor());
        cout << "Hi i'm " << players[i].getName() << endl;
        setConsoleColor(7);
    }

    delete[] players;
    std::cout << "Hello, Worlde!" << std::endl;
    system("pause");
    return 0;
}
