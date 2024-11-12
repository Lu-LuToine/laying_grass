#include "../include/Tiles.h"

#include <iostream>

Tiles::Tiles(){
    this->name = 0;
    this->player = 0;
    this->rotation = 0;
    this->flip = false;
};

Tiles::~Tiles(){
};

void Tiles::setName(int name){
    this->name = name;
};

int Tiles::getName(){
    return this->name;
};

void Tiles::setPlayer(int player){
    this->player = player;
};

int Tiles::getPlayer(){
    return this->player;
};

void Tiles::setRotation(int rotation){
    this->rotation = rotation;
};

int Tiles::getRotation(){
    return this->rotation;
};

void Tiles::setFlip(bool flip){
    this->flip = flip;
};

bool Tiles::getFlip(){
    return this->flip;
};
