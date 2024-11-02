#include "../src/Player.h"

using namespace std;

Player::Player() {
    this->name = "Player";
    this->color = "white";
    this->cells[1];
}

void Player::setName(std::string newName) {
    this->name = newName;
}

string Player::getName() {
    return this->name;
}

void Player::setColor(string color){
    this->color = color;
};

std::string Player::getColor(){
    return this->color;
};

void Player::setCells(int cell){
    this->cells[0] = cell;
};

int Player::getCells(){
    for (int i; i < sizeof this->cells; i++)
    return this->cells[0];
};