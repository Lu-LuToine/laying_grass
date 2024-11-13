#ifndef LAYING_GRASS_BOARD_H
#define LAYING_GRASS_BOARD_H

#include "Cells.h"

#include <vector>

class Board : public Cells{
private:
    int size;

public:
    Board();
    ~Board();

    void setSize(int);
    void setBoard();
    int getSize();
    void getBoard();

    std::vector<std::vector<Cells>> boardStruct;
};


#endif //LAYING_GRASS_BOARD_H
