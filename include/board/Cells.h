#ifndef LAYING_GRASS_CELLS_H
#define LAYING_GRASS_CELLS_H

class Cells{

protected:
    char status;

public:
    Cells();
    ~Cells();

    void setStatus(char);
    int getStatus() const;

};


#endif //LAYING_GRASS_CELLS_H
