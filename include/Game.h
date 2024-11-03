#ifndef LAYING_GRASS_GAME_H
#define LAYING_GRASS_GAME_H


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


#endif //LAYING_GRASS_GAME_H
