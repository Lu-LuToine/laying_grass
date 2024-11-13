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
        cin >> nb_player;
        do{
            setConsoleColor(64);
            cout << "[ERROR] - Chose between 2 and 9 players" << endl;
            cin >> nb_player;
        } while ( 2 > nb_player or nb_player > 9);

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

        chooseStats(players, game.getNbPlayer(), UsersColors);


        // [DEBUG] => check PLAYERS and colors
        // TODO : faire un affichage pour afficher chaque joueurs avec leur nom + le numéro de joueur (attention a faire i + 1 dans l'affichage)
        for (int i = 0; i < game.getNbPlayer(); i++) {
            setConsoleColor(players[i].getColor());
            cout << "Hi i'm " << players[i].getName() << endl;
            setConsoleColor(7);
        }

        Board1.getBoard();

        startingPlace(players, game);

        delete[] players;
        system("pause");
        return 0;
    }

}
