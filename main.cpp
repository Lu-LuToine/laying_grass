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
        cout << "[INIT] - How many Players (2-9) ? " << endl;
        cout << "*> :";
        cin >> nb_player;
        if (2 > nb_player or nb_player > 9) {
            do {
                setConsoleColor(64);
                cout << "[ERROR] - Chose between 2 and 9 players" << endl;
                setConsoleColor(10);
                cout << "*> :";
                cin >> nb_player;
            } while ( 2 > nb_player or nb_player > 9);
        }
        
        game.setNbPlayer(nb_player);

        setConsoleColor(10);
        cout << "[INIT] - You chose " << game.getNbPlayer() << " Players" << endl;

        Player* players = new Player[game.getNbPlayer()]; // Set players

        Board Board1;
        Board1.setSize(game.getNbPlayer());
        Board1.setBoard();
        //2
        //Board1.getBoard();

        Colors UsersColors;

        chooseStats(players, game.getNbPlayer(), UsersColors, game);

        //Board1.getBoard();

        startingPlace(players, game, Board1);
        Board1.getBoard(players);


        delete[] players;
        system("pause");
        return 0;
    }

}
