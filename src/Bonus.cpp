#include "../include/Bonus.h"

#include <iostream>

using namespace std;

Bonus::Bonus(){
    this->player = 0;
    this->name = "";
    this->status = 0;
    this->description = "";
};


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

void Bonus::setStatus(int status){
    this->status = status;
};

int Bonus::getStatus(){
    return this->status;
};

void Bonus::setDescription(string desc){
    this->description = desc;
};

std::string Bonus::getDescription(){
    return this->description;
};

Bonus::~Bonus(){};