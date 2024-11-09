#include "include/Player.h"
#include "include/board/Board.h"
#include "include/Colors.h"
#include "include/menu.h"
#include "include/Game.h"

#include <iostream>

using namespace std;

int main()
{
    startGameName();

    if (startGameMenu() == 3) {
        return 0;
    } else {
        Game game;
        int nb_player;

        setConsoleColor(32);
        cout << "[INIT-MENU] - First let's define the number of players " << endl;
        setConsoleColor(10);
        cout << "[INIT] - How many Players (2-9)" << endl;
        cin >> nb_player;

        game.setNbPlayer(nb_player);

        cout << "[INIT] - You chose " << game.getNbPlayer() << " Players" << endl;

        Player* players = new Player[nb_player]; // Set players

        Board Board1;
        Board1.setSize(game.getNbPlayer());
        Board1.setBoard();
        //2
        //Board1.getBoard();

        Colors UsersColors;

        chooseStats(players, nb_player, UsersColors);


        // [DEBUG] => check PLAYERS and colors
        for (int i = 0; i < nb_player; i++) {
            setConsoleColor(players[i].getColor());
            cout << "Hi i'm " << players[i].getName() << endl;
            setConsoleColor(7);
        }

        delete[] players;
        system("pause");
        return 0;
    }

}
