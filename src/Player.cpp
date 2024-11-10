#include "../include/Player.h"

#include <iostream>

using namespace std;

Player::Player() {
    this->name = "Player";
    this->color = 0;
    this->cells[1];
}

// ===== SETTERS =====

void Player::setName(std::string newName) {
    this->name = newName;
}

void Player::setColor(int color){
    this->color = color;
};

/*void Player::setCells(int cell){
    this->cells[0] = cell;
};*/

// ===== GETTERS =====

string Player::getName() {
    return this->name;
}

int Player::getColor(){
    return this->color;
};

pair<int, int> Player::getCells(){
    for (int i; i < sizeof this->cells; i++) {
        return this->cells[0];
    }
};


// TODO : une fonction set et get placement pour définir la position de départ du joueur
void Player::setBeginPlace(int cos1, int cos2){
    this->beginPlace = std::make_pair(cos1, cos2);
};

std::pair<int, int> Player::getBeginPlace() {
    return this->beginPlace;
};

Player::~Player() {}
