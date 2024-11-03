#include "../../include/board/Board.h"

Board::Board(){
    this->size = 0;
};

Board::~Board(){
    this->size;
};

void Board::setSize(int newSize){
    this->size = newSize;
};

int Board::getSize(){
    return this->size;
};