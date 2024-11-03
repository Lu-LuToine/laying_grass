#include "../../include/board/Cells.h"

Cells::Cells(){
    this->status = 0;
};

Cells::~Cells(){
    this->status;
};

void Cells::setStatus(int newStatus){
    this->status = newStatus;
};

int Cells::getStatus(){
    return this->status;
};