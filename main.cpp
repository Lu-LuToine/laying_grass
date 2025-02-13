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

    int menuReturn;
    do {
        menuReturn = startGameMenu();

        if (menuReturn == 2) {
            // Open the rules file and show rules
            openRulesFile("../rules.txt");
            cout << endl;
            setConsoleColor(7);
            continue;
        }


        if (menuReturn == 3) {
            // Exit the game
            return 0;
        }
    } while (menuReturn != 1);

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

    int totalBonuses = round(1.5*game.getNbPlayer()) + round(0.5*game.getNbPlayer()) + game.getNbPlayer(); // Set number of bonus
    Bonus* bonus = new Bonus[totalBonuses]; // Set bonus

    bonus->setBonuses(Board1, game, bonus);

    Colors UsersColors; // Set colors

    chooseStats(players, game.getNbPlayer(), UsersColors, game);
    Board1.getBoard(players);
    startingPlace(players, game, Board1);

    Tiles tiles;

    tiles.setForm(game);

    setConsoleColor(32);
    cout << endl;
    cout << "[INIT-MENU] - Initialization finished ! Good game at all " << endl;
    Board1.getBoard(players);
    setConsoleColor(11);
    tiles.displayQueueForm();
    gameLoop(game, Board1, bonus, players, tiles, totalBonuses);
    delete[] players;
    delete[] bonus;
    system("pause");
    return 0;
}

