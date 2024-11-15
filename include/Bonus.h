#ifndef LAYING_GRASS_BONUS_H
#define LAYING_GRASS_BONUS_H

#include <iostream>

class Bonus {

private:
    int player;
    std::string name;
    int status;
    std::string description;

public:

    Bonus();
    ~Bonus();

    void setPlayer(int);
    int getPlayer();

    void setName(std::string);
    std::string getName();

    void setStatus(int);
    int getStatus();

    void setDescription(std::string);
    std::string getDescription();

};


#endif //LAYING_GRASS_BONUS_H
