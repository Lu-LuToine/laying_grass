#ifndef LAYING_GRASS_TILES_H
#define LAYING_GRASS_TILES_H

#include <iostream>
#include <vector>

class Tiles {

private:
    std::string name;
    int player;
    char letters;
    int rotation;
    bool flip;
    std::vector<std::vector<int>> form;
    static std::vector<Tiles> allForms;

public:
    Tiles();
    ~Tiles();

    void setPlayer(int);
    int getPlayer();

    void setLetters();
    char getLetters();

    void setRotation(int);
    int getRotation();

    void setFlip(bool);
    bool getFlip();

    void setForm();
    std::vector<std::vector<int>> getForm() const;
    void debugDisplayAllForms();

};


#endif //LAYING_GRASS_TILES_H
