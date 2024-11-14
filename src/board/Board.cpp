#include "../../include/board/Board.h"
#include "../../include/Colors.h"

#include <iostream>
#include <vector>

#include "../../include/Player.h"


Board::Board(){
    this->size = 0;
    this->boardStruct;
}

// ===== SETTERS =====


void Board::setSize(int nbPlayers){
    if (nbPlayers < 5 ){
        this->size = 20;
    } else {
        this->size = 30;
    }
}

void Board::setBoard(){
    this->boardStruct.resize(this->size, std::vector<Cells>(this->size));

    for (int i = 0; i < this->size; i++) {
        std::vector<Cells> row;
        row.reserve(this->size);
        for (int j = 0; j < this->size; j++) {
            this->boardStruct[i][j] = Cells();
            this->boardStruct[i][j].setStatus(0);
        }
    }
    setConsoleColor(10);
    std::cout << "[INIT] - Board initialized successfully !" << std::endl;
}


// ===== GETTERS =====

int Board::getSize(){
    return this->size;
}


void Board::getBoard(Player players[]) {
    setConsoleColor(7);
    int row_count = 0;
    int cols_count = -1;

    for (int i = 0; i < this->size+1; ++i) {
        if (cols_count == -1) {
            std::cout << "  " << "   ";
        }
        else if (cols_count < 26){
            char lettersLine = 'A' + cols_count;
            std::cout << lettersLine << " ";
        } else {
            // Make this to not have a count with " { [ ..." instate of letters
            char lettersLine = 'a' + (cols_count - 26);
            std::cout << lettersLine << " ";
        }
        cols_count++;
    }

    std::cout << std::endl;

    for (const auto& row : this->boardStruct) {
        if (row_count < 10) {
            std::cout << '0' << row_count << " | ";
        } else {
            std::cout << row_count << " | ";

        }
        for (const Cells& cell : row) {
            switch (cell.getStatus()) {
                case 0:
                    std::cout << char(250) << ' ';
                    setConsoleColor(7);
                    break;
                case 1:
                    setConsoleColor(players[0].getColor());
                    std::cout << '1' << ' ';
                    setConsoleColor(7);
                    break;
                case 2:
                    setConsoleColor(players[1].getColor());
                    std::cout << "2" << ' ';
                    setConsoleColor(7);
                    break;
                case 3:
                    setConsoleColor(players[2].getColor());
                    std::cout << "3" << ' ';
                    setConsoleColor(7);
                    break;
                case 4:
                    setConsoleColor(players[3].getColor());
                    std::cout << "4" << ' ';
                    setConsoleColor(7);
                    break;
                case 5:
                    setConsoleColor(players[4].getColor());
                    std::cout << "5" << ' ';
                    setConsoleColor(7);
                    break;
                case 6:
                    setConsoleColor(players[5].getColor());
                    std::cout << "6" << ' ';
                    setConsoleColor(7);
                    break;
                case 7:
                    setConsoleColor(players[6].getColor());
                    std::cout << "7" << ' ';
                    setConsoleColor(7);
                    break;
                case 8:
                    setConsoleColor(players[7].getColor());
                    std::cout << "8" << ' ';
                    setConsoleColor(7);
                    break;
                case 9:
                    setConsoleColor(players[8].getColor());
                    std::cout << "9" << ' ';
                    setConsoleColor(7);
                    break;
                default:
                    setConsoleColor(7);
                    break;
            }
        }
        row_count++;
        std::cout << std::endl;
    }
}



Board::~Board(){}
