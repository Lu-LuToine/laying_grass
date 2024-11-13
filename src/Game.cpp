#include "../include/Game.h"
#include "../include/Colors.h"
#include "../include/Player.h"

#include <iostream>

using namespace std;

Game::Game(){
    this->turn = 0;
    this->nbPlayer = 0;
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

void startingPlace(Player players[], Game game){
    for (int i = 0; i < game.getNbPlayer(); i++) {
        int x;
        int y;

        setConsoleColor(players[i].getColor());
        cout << "Player " << i+1 << endl;
        setConsoleColor(10);
        cout << "Choose your starting place x (a letter) : " << endl;
        cout << "*> ";
        cin >> x;
        cout << "Choose your starting place y (a number) : " << endl;
        cout << "*> ";
        cin >> y;
        players[i].setBeginPlace(x, y);
        cout << "Player " << i + 1 << " start at x " <<  players[i].getBeginPlace().first << " and y " << players[i].getBeginPlace().second << endl;
    }
}

Game::~Game(){};
