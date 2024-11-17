#include "../include/Bonus.h"
#include "../include/Game.h"
#include "../include/board/Board.h"

#include <cmath>
#include <iostream>

using namespace std;

Bonus::Bonus(){
    this->player = 0;
    this->name = "";
    this->description = "";
    this->position;
    this->bonusType;
};

void Bonus::setBonuses(Board &board, Game game, Bonus bonus[]){

    double probaBonus[3];

    probaBonus[0] = round(1.5*game.getNbPlayer());
    probaBonus[1] = round(0.5*game.getNbPlayer());
    probaBonus[2] = game.getNbPlayer();

    srand(time(0));

    for(int j = 0; j < sizeof(probaBonus); j++){
        for(int i = 0; i < int(probaBonus[j]); i++){
            int k = 0;

            int random, random2;

            do {
                random = rand() % board.getSize();
                random2 = rand() % board.getSize();
            } while (board.boardStruct[random][random2].getStatus() != 0 || random == 0 || random2 == 0 || random == board.getSize() || random2 == board.getSize() || !cardinateStatusCases(board, random, random2, true, 0));

            board.boardStruct[random][random2] = Cells();
            board.boardStruct[random][random2].setStatus(j + 10);

            bonus[k] = Bonus();
            bonus[k].setType(j);
            bonus[k].setPositon(random, random2);

            if (j == 0) {
                bonus[k].setName("Tile Exchange");
                bonus[k].setDescription("Exchange your current tile with a tile in the queue.");
            }
            else if (j == 1) {
                bonus[k].setName("Stone");
                bonus[k].setDescription("Place a stone and block your enemy.");
            }
            else if (j == 2) {
                bonus[k].setName("Robbery");
                bonus[k].setDescription("Choose a tile from your enemy territory, this tile becomes part of your territory.");
            }
            k++;
            debug();
        }
    }
};

void Bonus::debug() {
    std::cout << "Bonus Info:" << std::endl;
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Description: " << this->getDescription() << std::endl;
    std::cout << "Type: " << this->getType() << std::endl;
    std::cout << "Position: (" << this->getPositon().first << ", " << this->getPositon().second << ")" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void Bonus::setPositon(int x, int y) {
    this->position = std::make_pair(x, y);
}

std::pair<int, int> Bonus::getPositon() {
    return this->position;
}

void Bonus::setPlayer(int player){
    this->player = player;
};

int Bonus::getPlayer(){
    return this->player;
};

void Bonus::setName(std::string name){
    this->name = name;
};

std::string Bonus::getName(){
    return this->name;
};

void Bonus::setDescription(string desc){
    this->description = desc;
};

std::string Bonus::getDescription(){
    return this->description;
};

void Bonus::setType(int type) {
    this->bonusType = type;
}

int Bonus::getType() {
    return this->bonusType;
}

Bonus::~Bonus(){};