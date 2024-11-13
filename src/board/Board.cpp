#include "../../include/board/Board.h"
#include "../../include/Colors.h"

#include <iostream>
#include <vector>


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


void Board::getBoard() {
    setConsoleColor(7);
    int row_count = 1;
    int cols_count = -1;

    for (int i = 0; i < this->size+1; ++i) {
        if (cols_count == -1){
            std::cout << "  " << "   ";
        } else if (cols_count < 26){
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
            if (cell.getStatus() == 0){ //Empty
                std::cout << char(250) << ' ';
            }
            else if (cell.getStatus() == 1){
                std::cout << '1' << ' ';
            }
            else if (cell.getStatus() == 2){
                std::cout << "2" << ' ';
            }  else {
                // Optional: Handle unexpected cell status if needed
                std::cout << '?' << ' ';
            }
        }
        row_count++;
        std::cout << std::endl;
    }
}



Board::~Board(){}
