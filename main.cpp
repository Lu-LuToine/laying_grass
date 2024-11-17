#include "include/Player.h"
#include "include/board/Board.h"
#include "include/Colors.h"
#include "include/menu.h"
#include "include/Game.h"
#include "include/Tiles.h"
#include "include/Bonus.h"

#include <iostream>
#include <cmath>


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

        int totalBonuses = round(1.5*game.getNbPlayer()) + round(0.5*game.getNbPlayer()) + game.getNbPlayer();
        Bonus* bonus = new Bonus[totalBonuses];



        bonus->setBonuses(Board1, game, bonus);


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


                for (int i = 0; i < nb_player; i++) {
                    do {
                    cout << "PLAYER " << i + 1 << endl;  // Affiche le joueur actuel (ajoute 1 pour un affichage humain)
                    cout << "DEBUG - What do ? :" << endl;
                    cout << "DEBUG - 0 Placement" << endl;
                    cout << "DEBUG - 1 Rotate" << endl;
                    cin >> action;

                    switch (action) {
                        case 0:
                            cout << "DEBUG - placement de la tuile : x :" << endl;
                        cin >> placementx;
                        cout << "DEBUG - placement de la tuile : y :" << endl;
                        cin >> placementy;

                        tiles.placeFormInBoard(Board1, placementx, placementy, i+1, players);

                        placed = true;
                        Board1.getBoard(players);
                        break;

                        case 1:
                            tiles.rotateForm();
                        tiles.displayCurrentTile();
                        break;

                        default:
                            cout << "[ERROR] - Action non reconnue" << endl;
                        break;

                    }
                    bonusCaptured(game, Board1, bonus, totalBonuses);
                    for (int j = 0; j < totalBonuses; j++) {
                         bonus[j].debug();
                    }
                    tiles.displayQueueForm();
                }while (!placed);
            }

                test++;


        } while (test != 3);


        delete[] players;
        delete[] bonus;
        system("pause");
        return 0;
    }
}
