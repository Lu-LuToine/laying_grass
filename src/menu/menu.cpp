#include "../../include/menu.h"
#include "../../include/colors.h"

#include <unistd.h>
#include <iostream>

using namespace std;

void startGameMenu() {
    int user_choice;
    setConsoleColor(14);
    cout << ">>==========================================================<<" <<endl;
    usleep(200000);
    cout << "||                                                          ||" <<endl;
    usleep(200000);
    cout << "|| _    ____ _   _ _ _  _ ____    ____ ____ ____ ____ ____  ||" <<endl;
    usleep(200000);
    cout << "|| |    |__|  \\_/  | |\\ | | __    | __ |__/ |__| [__  [__   ||" <<endl;
    usleep(200000);
    cout << "|| |___ |  |   |   | | \\| |__]    |__] |  \\ |  | ___] ___]  ||" <<endl;
    usleep(200000);
    cout << "||                        Console Game                      ||" <<endl;
    usleep(200000);
    cout << "||                                                          ||" <<endl;
    usleep(200000);
    cout << ">>==========================================================<<" <<endl;
    cout << endl;
    usleep(200000);


    setConsoleColor(46);
    cout << "          [START MENU] - Welcome on 'Laying Grass'            " << endl;
    setConsoleColor(32);
    cout << "         [START MENU] - Choose your next action :             " << endl;
    cout << "         [START MENU] - 1 : Start game                        " << endl;
    cout << "         [START MENU] - 2 : Display rules                     " << endl;
    cout << "         [START MENU] - 3 : Leave                             " << endl;
    setConsoleColor(10);
    cout << "*> :";
    cin >> user_choice;
}

void chooseStats(){

};
