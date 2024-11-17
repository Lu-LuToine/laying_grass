#ifndef LAYING_GRASS_GAME_H
#define LAYING_GRASS_GAME_H

#include "Player.h"
#include "board/Board.h"

#include <vector>

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

};

bool cardinateStatusCases(Board &board, int x, int y, bool allAndCases, int value);
void startingPlace(Player players[], Game game, Board &board);
int convertLetterToCoos(char);
void bonusCaptured(Board &board, Game game);

#endif //LAYING_GRASS_GAME_H
