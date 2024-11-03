#ifndef LAYING_GRASS_BOARD_H
#define LAYING_GRASS_BOARD_H

#include "Cells.h"

#include <vector>

class Board : public Cells{
private:
    int size;
    std::vector<std::vector<Cells>> boardStruct;

public:
    Board();
    ~Board();

    void setSize(int);
    void setBoard();
    int getSize();
    void getBoard();

};


#endif //LAYING_GRASS_BOARD_H
