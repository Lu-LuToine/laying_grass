#ifndef LAYING_GRASS_PLAYER_H
#define LAYING_GRASS_PLAYER_H

#include <iostream>
#include <vector>

class Player {
private:
    std::string name;
    int color;
    std::vector<std::pair<int, int>> cells; // => Using "pair" to use (x, y) position
    std::pair<int, int> beginPlace;
    std::vector<int> bonus;

public:
    Player();
    ~Player();

    void setName(std::string);
    void setColor(int);
    void setCells(int x, int y);
    void setBeginPlace(int, int);
    void setBonus(int);
    void deleteBonus(int);

    std::string getName();
    int getColor();

    std::vector<std::pair<int, int>> getCells();
    std::pair<int, int> getBeginPlace();
    std::vector<int> getBonus();
};


#endif //LAYING_GRASS_PLAYER_H
