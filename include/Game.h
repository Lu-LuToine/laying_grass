#ifndef LAYING_GRASS_GAME_H
#define LAYING_GRASS_GAME_H

#include "Player.h"
#include "board/Board.h"
#include "Bonus.h"
#include "Tiles.h"

#include <vector>

class Bonus;
class Tiles;

class Game {

private:
    int turn;
    int nbPlayer;

public:

    Game();
    ~Game();

    void setTurn(int);
    int getTurn();

    void setNbPlayer(int);
    int getNbPlayer();

    void endGameCalculTerritory(Player players[], Board &board);

};

bool cardinateStatusCases(Board &board, int x, int y, bool allAndCases, int value);
void startingPlace(Player players[], Game game, Board &board);
int convertLetterToCoos(char);
void bonusCaptured(Game &game, Board &board, Bonus bonus[], Player players[], int bonusSize);
void gameLoop(Game &game, Board &board, Bonus bonus[], Player players[], Tiles &tiles, int totalBonuses);


#endif //LAYING_GRASS_GAME_H
