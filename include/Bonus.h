#ifndef LAYING_GRASS_BONUS_H
#define LAYING_GRASS_BONUS_H

#include "Game.h"
#include "board/Board.h"

#include <iostream>

class Game;

class Bonus {

private:
    int player;
    std::string name;
    int status;
    std::string description;
    std::pair<int, int> position;
    int bonusType;
    bool useNow;
    bool used;

public:

    Bonus();

    void setBonuses(Board &board, Game &game, Bonus bonus[]);


    void debug();

    void setPosition(int x, int y);

    std::pair<int, int> getPosition();

    ~Bonus();

    void setPlayer(int);
    int getPlayer();

    void setName(std::string);
    std::string getName();

    void setUseNow(bool now);

    bool getUseNow();

    void setUsed(bool used);

    bool getUsed();

    void setDescription(std::string);
    std::string getDescription();

    void setType(int type);

    int getType();
};

void afficherTousLesBonus(Bonus bonus[], int tailleBonus);

#endif //LAYING_GRASS_BONUS_H
