#ifndef LAYING_GRASS_PLAYER_H
#define LAYING_GRASS_PLAYER_H

#include <iostream>
#include <list>
#include <vector>

class Player {
private:
    std::string name;
    int color;
    std::vector<std::pair<int, int>> cells; // => Using "pair" to use (x, y) position
    std::pair<int, int> beginPlace;

public:
    Player();
    ~Player();

    void setName(std::string);
    void setColor(int);
    void setCells(int);
    void setBeginPlace(int, int);

    std::string getName();
    int getColor();
    std::pair<int, int> getCells();
    std::pair<int, int> getBeginPlace();
};


#endif //LAYING_GRASS_PLAYER_H
