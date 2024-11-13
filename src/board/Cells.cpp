#include "../../include/board/Cells.h"

Cells::Cells(){
    this->status = 0;
};

// ===== SETTERS =====

void Cells::setStatus(int newStatus){
    this->status = newStatus;
};


// ===== GETTERS =====

int Cells::getStatus() const{
    return this->status;
};


Cells::~Cells(){};
