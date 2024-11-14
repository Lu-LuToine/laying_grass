#include "../../include/board/Cells.h"

Cells::Cells(){
    this->status = 0;
    this->player = 0;
};

// ===== SETTERS =====

void Cells::setStatus(int newStatus){
    this->status = newStatus;
};

void Cells::setPlayer(int playerAssigned) {
    this->player = playerAssigned;
}


// ===== GETTERS =====

int Cells::getStatus() const{
    return this->status;
};

int Cells::getPlayer() const{
    return this->player;
}


Cells::~Cells(){};
