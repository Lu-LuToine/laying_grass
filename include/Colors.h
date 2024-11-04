#ifndef COLORS_H
#define COLORS_H

#include <iostream>
#include <map>

void setConsoleColor(int color);

class Colors{

private:
    std::map<char, char> colors;

public:
    Colors();
    ~Colors();
    std::map<char, int> getColors();
    std::map<char, int> removeColor(int);
};

#endif //COLORS_H
