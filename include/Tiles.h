#ifndef LAYING_GRASS_TILES_H
#define LAYING_GRASS_TILES_H

#include "Game.h"


#include <iostream>
#include <vector>
#include <string>

class Game;

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

    // Static functions
    static void setForm(Game &game);

    static void debugDisplayAllForms();

    std::vector<std::vector<int>> rotate90(const std::vector<std::vector<int>> &matrice) const;

    bool isSameShape(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) const;

    void rotateForm();

    void flipForm();

    void displayCurrentTile();

    bool placeFormInBoard(Board &board, int player_x, int player_y, int currentPlayer, Player player[]);

    void displayQueueForm() ;

    int tileExchange(Board &board);

    std::vector<std::vector<int>> getForm() const;
};

#endif //LAYING_GRASS_TILES_H
