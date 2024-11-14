#include "../include/Game.h"
#include "../include/Colors.h"
#include "../include/Player.h"

#include <iostream>
#include <random>

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

int convertLetterToCoos(char letter){
    int yco = int(letter);
    cout << "LETTER RESULT" << yco-65 << endl;
    if (yco-65 > 26){
        return yco-71;
    } else {
        return yco-65;
    }
};

void startingPlace(Player players[], Game game, Board &board){
    for (int i = 0; i < game.getNbPlayer(); i++) {
        int x;
        char y;
        int yco;

        setConsoleColor(players[i].getColor());
        cout << "Player " << i+1 << endl;
        setConsoleColor(10);
        cout << "Choose your starting place x (a number) : " << endl;
        cout << "*> ";
        cin >> x;
        cout << "Choose your starting place y (a letter) : " << endl;
        cout << "*> ";
        cin >> y;
        yco = convertLetterToCoos(y);
        players[i].setBeginPlace(x, yco);
        cout << "Player " << i + 1 << " start at x " <<  players[i].getBeginPlace().first << " and y " << players[i].getBeginPlace().second << endl;

        board.boardStruct[x][yco] = Cells();
        board.boardStruct[x][yco].setStatus(i + 1);

        board.getBoard(players);
    }
}

void setBonuses(){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(10,12);
    int random = distribution(generator);
    cout << random << endl;
    //board.boardStruct[x][yco] = Cells();
};

Game::~Game(){};
