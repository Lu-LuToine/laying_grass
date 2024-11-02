#ifndef LAYING_GRASS_PLAYER_H
#define LAYING_GRASS_PLAYER_H

#include <iostream>

class Player {
private:
    std::string name;
    std::string color;
    int cells[];

public:
    Player();
    ~Player();
    void setName(std::string);
    std::string getName();
    void setColor(std::string );
    std::string getColor();
    void setCells(int);
    int getCells();
};


#endif //LAYING_GRASS_PLAYER_H
