#include "../include/Tiles.h"

#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

#include "../include/Game.h"

std::vector<Tiles> Tiles::allForms;

Tiles::Tiles(){
    this->name =  "";
    this->player = 0;
    this->rotation = 0;
    this->letters = 'a';
    this->flip = false;
    this->form;
};

void Tiles::setPlayer(int player){
    this->player = player;
};

int Tiles::getPlayer() const{
    return this->player;
};

void Tiles::setLetters() {

}

char Tiles::getLetters() const {
    return this->letters;
}


void Tiles::setRotation(int rotation){
    this->rotation = rotation;
};

int Tiles::getRotation() const{
    return this->rotation;
};

void Tiles::setFlip(bool flip){
    this->flip = flip;
};

bool Tiles::getFlip() const{
    return this->flip;
};

void Tiles::setForm(Game game) {
    int count = 97;
    allForms.clear();

    for (int i = 1; i < count; i++) {
        std::string filename = "../tiles/tile" + std::to_string(i) + ".txt";
        std::vector<std::vector<int>> shape;
        std::ifstream file(filename);
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::vector<int> row;
                for (char c : line) {
                    if (c == '*') {
                        row.push_back(1);
                    } else if (c == '.') {
                        row.push_back(0);
                    }
                }
                shape.push_back(row);
            }
            file.close();
        } else {
            std::cerr << "Error - can't open this file : " << filename << std::endl;
        }

        Tiles tile;
        tile.name = "tile" + std::to_string(i);
        tile.form = shape;
        allForms.push_back(tile);
    }

    // Shuffle allForms ; adapt to get different result every time restart game
    srand(time(0));
    std::default_random_engine engine(static_cast<unsigned int>(time(0)));

    std::shuffle(allForms.begin(), allForms.end(), engine);

    // Set number of tiles to suit of number of players
    int nbPlayers = game.getNbPlayer() ;
    int nbTiles = round(10.67 * nbPlayers);
    int nbTilesToRemove = allForms.size() - nbTiles;

    for (int i = 0; i < nbTilesToRemove; ++i) {
        allForms.pop_back();
    }

    std::cout << allForms.size() << std::endl;
}

void Tiles::debugDisplayAllForms() {
    for (size_t i = 0; i < allForms.size(); ++i) {
        const Tiles& tile = allForms[i];
        std::cout << "Tile " << i << " (" << tile.name << "):" << std::endl;

        // Afficher la forme ligne par ligne
        for (const auto& row : tile.form) {
            for (int cell : row) {
                std::cout << (cell == 1 ? char(219) : ' ');
            }
            std::cout << std::endl; // Passer à la ligne suivante
        }
        std::cout << "-------------------------" << std::endl;
    }
}

void Tiles::displayQueueForm() const {
    size_t maxHeight = 0;
    size_t formsToDisplay = std::min(allForms.size(), size_t(5));

    for (size_t i = 0; i < formsToDisplay; ++i) {
        maxHeight = std::max(maxHeight, allForms[i].form.size());
    }

    for (size_t row = 0; row < maxHeight; ++row) {
        for (size_t i = 0; i < formsToDisplay; ++i) {
            const auto& tile = allForms[i];

            if (row < tile.form.size()) {
                for (int val : tile.form[row]) {
                    std::cout << (val ? char(219) : ' ');
                }
            } else {
                for (size_t col = 0; col < tile.form[0].size(); ++col) {
                    std::cout << ' ';
                }
            }

            std::cout << "  ";
        }
        std::cout << '\n';
    }
}



std::vector<std::vector<int>> Tiles::getForm() const {
    return this->form;
}

Tiles::~Tiles(){
};

