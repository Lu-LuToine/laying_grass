#ifndef LAYING_GRASS_BONUS_H
#define LAYING_GRASS_BONUS_H

#include <iostream>

#include "Game.h"

class Bonus {

private:
    int player;
    std::string name;
    int status;
    std::string description;
    std::pair<int, int> position;
    int bonusType;

public:

    Bonus();

    void setBonuses(Board &board, Game game, Bonus bonus[]);

    void debug();

    void setPositon(int x, int y);

    std::pair<int, int> getPositon();

    ~Bonus();

    void setPlayer(int);
    int getPlayer();

    void setName(std::string);
    std::string getName();

    void setDescription(std::string);
    std::string getDescription();

    void setType(int type);

    int getType();
};


#endif //LAYING_GRASS_BONUS_H
