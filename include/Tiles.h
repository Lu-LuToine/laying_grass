#ifndef LAYING_GRASS_TILES_H
#define LAYING_GRASS_TILES_H

#include <iostream>
#include <vector>
#include <string>

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
    int getPlayer() const;

    void setLetters();
    char getLetters() const;

    void setRotation(int);
    int getRotation() const;

    void setFlip(bool);
    bool getFlip() const;

    // Static functions
    static void setForm();
    static void debugDisplayAllForms();

    // Non-static function to get a specific form
    std::vector<std::vector<int>> getForm() const;
};

#endif //LAYING_GRASS_TILES_H
