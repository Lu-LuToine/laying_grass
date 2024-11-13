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
    std::vector<std::string> bonus;

public:
    Player();
    ~Player();

    void setName(std::string);
    void setColor(int);
    void setCells(int);
    void setBeginPlace(int, int);
    void setBonus(std::string);
    void deleteBonus(std::string);

    std::string getName();
    int getColor();
    std::pair<int, int> getCells();
    std::pair<int, int> getBeginPlace();
    std::vector<std::string> getBonus();
};


#endif //LAYING_GRASS_PLAYER_H
