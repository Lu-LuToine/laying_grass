#include "../include/Game.h"

Game::Game(){
    this->turn = 0;
    this->nbPlayer = 0;
};

Game::~Game(){
    this->turn;
    this->nbPlayer;
};

void Game::setTurn(int turn){
    this->turn = turn;
};

int Game::getTurn(){
    return this->turn;
};

void Game::setNbPlayer(int nbPlayer){
    this->nbPlayer = nbPlayer;
};

int Game::getNbPlayer(){
    return this->nbPlayer;
};