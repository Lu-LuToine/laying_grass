#include "../include/Game.h"
#include "../include/Colors.h"
#include "../include/Player.h"
#include "../include/Bonus.h"

#include <iostream>
#include <random>
#include <vector>

using namespace std;

/*Game Class*/
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


/*Others Functions*/
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

        if (board.getSize() <= 20 && (0 > x || x > 20 || 65 > int(y) || int(y) > 84) ){ // Check if x and y are correct
            do {
                setConsoleColor(79);
                cout << "[ERROR] - Chose a valid X position (between 0 and 20)" << endl;
                setConsoleColor(10);
                cout << "Choose your starting place x (a number) : " << endl;
                cout << "*> ";
                cin >> x;

                setConsoleColor(79);
                cout << "[ERROR] - Chose a valid Y position (between A and T)" << endl;
                setConsoleColor(10);
                cout << "Choose your starting place y (a number) : " << endl;
                cout << "*> ";
                cin >> y;
            } while (0 > x || x > 20 || 65 > int(y) || int(y) > 84);
        }

        yco = convertLetterToCoos(y);
        players[i].setBeginPlace(x, yco);
        cout << "Player " << i + 1 << " start at x " <<  players[i].getBeginPlace().first << " and y " << players[i].getBeginPlace().second << endl;

        board.boardStruct[x][yco] = Cells();
        board.boardStruct[x][yco].setStatus(i + 1);

        board.getBoard(players);
    }
}


bool cardinateEmptyCases(Board &board, int x, int y) {
    // 4 corners
    if(x == 0 && y == 0) {
        if (board.boardStruct[x][y + 1].getStatus() == 0 && board.boardStruct[x + 1][y].getStatus() == 0) {
            return true;
        }
    }

    else if(x == 0 && y == board.getSize()) {
        if (board.boardStruct[x - 1][y].getStatus() == 0 && board.boardStruct[x][y + 1].getStatus() == 0) {
            return true;
        }
    }

    else if(y == 0 && x == board.getSize()) {
        if (board.boardStruct[x][y - 1].getStatus() == 0 && board.boardStruct[x + 1][y].getStatus() == 0) {
            return true;
        }

    }

    else if(x  == board.getSize() && y == board.getSize()) {
        if (board.boardStruct[x - 1][y].getStatus() == 0 && board.boardStruct[x][y - 1].getStatus() == 0) {
            return true;
        }

    }


    // -------------------------------------


    // 4 lines

    // Top line
    else if(x == 0 && y < board.getSize() -1 ) {
        if (board.boardStruct[x][y - 1].getStatus() == 0 && board.boardStruct[x][y + 1].getStatus() == 0 && board.boardStruct[x + 1][y].getStatus() == 0) {
            return true;
        }

    }

    // Left line
    else if(y == 0 && x < board.getSize() -1 ) {
        if (board.boardStruct[x - 1][y].getStatus() == 0 && board.boardStruct[x + 1][y].getStatus() == 0 && board.boardStruct[x][y + 1].getStatus() == 0) {
            return true;
        }

    }

    // Bottom line
    else if(y == board.getSize() && x < board.getSize() -1 ) {
        if (board.boardStruct[x][y - 1].getStatus() == 0 && board.boardStruct[x][y + 1].getStatus() == 0 && board.boardStruct[x - 1][y].getStatus() == 0) {
            return true;
        }

    }

    // Right line
    else if(x == board.getSize() && y < board.getSize() -1 ) {
        if (board.boardStruct[x - 1][y].getStatus() == 0 && board.boardStruct[x + 1][y].getStatus() == 0 && board.boardStruct[x][y - 1].getStatus() == 0) {
            return true;
        }
    }

    // -------------------------------------


    // Default
    else if(x > 0 && x < board.getSize() - 1 && y > 0 && y < board.getSize() - 1) {
        if (board.boardStruct[x][y + 1].getStatus() == 0 && board.boardStruct[x + 1][y].getStatus() == 0 && board.boardStruct[x - 1][y].getStatus() == 0 && board.boardStruct[x][y - 1].getStatus() == 0) {
            return true;
        }
    }

    return false;

}

void setBonuses(Board &board, Game game){

    double probaBonus[3];

    probaBonus[0] = round(1.5*game.getNbPlayer());
    probaBonus[1] = round(0.5*game.getNbPlayer());
    probaBonus[2] = game.getNbPlayer();

    srand(time(0));

    for(int j = 0; j < sizeof(probaBonus); j++){
        for(int i = 0; i < int(probaBonus[j]); i++){

            int random, random2;

            do {
                random = rand() % board.getSize();
                random2 = rand() % board.getSize();
            } while (board.boardStruct[random][random2].getStatus() != 0 || !cardinateEmptyCases(board, random, random2));

            board.boardStruct[random][random2] = Cells();
            board.boardStruct[random][random2].setStatus(j + 10);

            cout << "bonus random" << random << " " << random2 << " status" << board.boardStruct[random][random2].getStatus() << endl;
        }
    }

};

Game::~Game(){};
