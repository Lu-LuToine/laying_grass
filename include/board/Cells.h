#ifndef LAYING_GRASS_CELLS_H
#define LAYING_GRASS_CELLS_H

class Cells{

protected:
    int status;
    int player;

public:
    Cells();
    ~Cells();

    void setStatus(int);
    void setPlayer(int);
    int getStatus() const;
    int getPlayer() const;
};


#endif //LAYING_GRASS_CELLS_H
