#ifndef LAYING_GRASS_TILES_H
#define LAYING_GRASS_TILES_H

#include <iostream>

class Tiles {

private:
    int name;
    int player;
    int rotation;
    bool flip;


public:
    Tiles();
    ~Tiles();

    void setName(int);
    int getName();

    void setPlayer(int);
    int getPlayer();

    void setRotation(int);
    int getRotation();

    void setFlip(bool);
    bool getFlip();

};


#endif //LAYING_GRASS_TILES_H
