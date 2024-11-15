#ifndef LAYING_GRASS_GAME_H
#define LAYING_GRASS_GAME_H

#include "Player.h"
#include "board/Board.h"

#include <vector>

class Game {

private:
    int turn;
    int nbPlayer;
    std::vector<int> initBonus;

public:

    Game();
    ~Game();

    void setTurn(int);
    int getTurn();

    void setNbPlayer(int);
    int getNbPlayer();

    std::vector<int> getInitBonus();
    std::vector<int> removeInitBonus(int);
};

void startingPlace(Player players[], Game game, Board &board);
int convertLetterToCoos(char);
void setBonuses(Board &board, Game game);

#endif //LAYING_GRASS_GAME_H
