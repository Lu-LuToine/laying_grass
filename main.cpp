#include "include/Player.h"
#include "include/board/Board.h"
#include "include/Colors.h"
#include "include/menu.h"
#include "include/Game.h"
#include "include/Tiles.h"
#include "include/Bonus.h"

#include <iostream>

using namespace std;

int main()
{
    startGameName();

    /*Bonus Initialization*/
    Bonus TileExchange;
    Bonus Stone;
    Bonus Robbery;

    TileExchange.setName("Tile Exchange");
    TileExchange.setDescription("Exchange your current tile with a tile in the queue.");

    Stone.setName("Stone");
    Stone.setDescription("Place a stone and block your enemy.");

    Robbery.setName("Robbery");
    Robbery.setDescription("Choose a tile from your enemy territory, this tile becames part of your's territory.");

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

        setBonuses(Board1, game);

        //2
        Board1.getBoard(players);

        Colors UsersColors;

        chooseStats(players, game.getNbPlayer(), UsersColors, game);

        //Board1.getBoard();

        startingPlace(players, game, Board1);
        Board1.getBoard(players);
        Tiles tiles;

        tiles.setForm(game);
        tiles.displayQueueForm();

        int test = 0;
        do {
            int placementx;
            int placementy;
            int action;
            bool placed = false;

            do {
                cout << "DEBUG - What do ? :" << endl;
                cout << "DEBUG - 0 Placement" << endl;
                cout << "DEBUG - 1 Rotate" << endl;
                cin >> action;

                switch (action) {
                    case 0 :
                        cout << "DEBUG - placement de la tuile : x :" << endl;
                        cin >> placementx;
                        cout << "DEBUG - placement de la tuile : y :" << endl;
                        cin >> placementy;

                        tiles.placeFormInBoard(Board1, placementx, placementy, 1, players);

                        placed = true;
                        Board1.getBoard(players);
                        break;
                    case 1:
                        tiles.rotateForm();
                        tiles.displayCurrentTile();
                        break;
                    default:
                        cout << "kaka";
                        break;;
                }


            } while (!placed);

            tiles.displayQueueForm();
            test++;
        }while(test !=3);




        delete[] players;
        system("pause");
        return 0;
    }
}
