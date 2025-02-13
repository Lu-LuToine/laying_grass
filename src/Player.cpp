#include "../include/Player.h"

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

Player::Player() {
    this->name = "Player";
    this->color = 0;
    this->cells = {};
    this->bonus = {};
}

// ===== SETTERS =====

void Player::setName(std::string newName) {
    this->name = newName;
}

void Player::setColor(int color){
    this->color = color;
};

void Player::setCells(int x, int y){
    this->cells.emplace_back(x, y);
};

void Player::setBonus(int bonus){
    this->bonus.insert(this->bonus.end(), bonus);
};

// ===== GETTERS =====

string Player::getName() {
    return this->name;
}

int Player::getColor(){
    return this->color;
};

std::vector<std::pair<int, int>> Player::getCells() {
    return this->cells;
}


void Player::setBeginPlace(int cos1, int cos2){
    this->beginPlace = std::make_pair(cos1, cos2);
};

pair<int, int> Player::getBeginPlace() {
    return this->beginPlace;
};

vector<int> Player::getBonus(){
    return this->bonus;
};

Player::~Player() {};

// ===== Functions =====

void Player::deleteBonus(int deletedElement){
    this->bonus.erase(std::next(this->bonus.begin(), deletedElement));
};





