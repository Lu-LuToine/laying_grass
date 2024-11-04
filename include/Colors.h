#ifndef COLORS_H
#define COLORS_H

#include <iostream>
#include <map>

void setConsoleColor(int color);

class Colors{

private:
    std::map<std::string, int> colors;

public:
    Colors();
    ~Colors();

    void setColors();
    std::map<std::string, int> getColors();
    void removeColor(const std::string &color);

    void getColorsInfos() const;

};

#endif //COLORS_H
