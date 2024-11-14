#ifndef LAYING_GRASS_GAME_H
#define LAYING_GRASS_GAME_H


#include "Player.h"
#include "board/Board.h"

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

void startingPlace(Player players[], Game game, Board &board);
int convertLetterToCoos(char);
void setBonuses();

#endif //LAYING_GRASS_GAME_H
