#ifndef LAYING_GRASS_PLAYER_H
#define LAYING_GRASS_PLAYER_H

#include <iostream>
#include <vector>

class Player {
private:
    std::string name;
    int color;
    std::vector<std::pair<int, int>> cells; // => Using "pair" to use (x, y) position

public:
    Player();
    ~Player();

    void setName(std::string);
    void setColor(int);
    void setCells(int);
    void setBeginPlace(int coordonnees[1]);

    std::string getName();
    int getColor();
    std::pair<int, int> getCells();
    int getBeginPlace();
};


#endif //LAYING_GRASS_PLAYER_H
