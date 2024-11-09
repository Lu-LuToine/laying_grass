#include "../../include/menu.h"
#include "../../include/Colors.h"
#include "../../include/Player.h"

#include <unistd.h>
#include <iostream>
#include <map>

using namespace std;

void startGameName() {
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
}

void startGameMenu(){
    int user_choice;
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

void chooseStats(Player players[], int nb_player, Colors chooseColors){
    setConsoleColor(32);
    cout << "[INIT-MENU] - Now choose player's name and player's colors" << endl;
    setConsoleColor(10);
    for (int i = 0; i < nb_player; i++) {
        string name;
        string color;

        cout << "[INIT] - Players's " << i + 1 << " name : " << endl;
        cout << "*> :";
        cin >> name;

        do {
            setConsoleColor(10);
            cout << "[INIT] - Choose colors (you can see all available colors with : 'colors') : "<< endl;
            cout << "*> :";
            cin >> color;
            if (color == "colors"){
                chooseColors.getColorsInfos();
            }
        } while (chooseColors.getColorCode(color) == 0);

        players[i].setName(name);
        int colorCode = chooseColors.getColorCode(color);
        players[i].setColor(colorCode);

        setConsoleColor(players[i].getColor());
        cout << "[INIT] - Player "  << i + 1 << " Your name is " << players[i].getName() << endl;

        chooseColors.removeColor(color);
        setConsoleColor(10);
        cout << "[INIT] - '" << color << "' is now removed from available colors"  << endl;
    }

};

//DEBUG MOI
void DEBUGchooseStats(Player players[], int nb_player){

    for (int i = 0; i < nb_player; i++) {
        if (i == 1) {
            players[i].setName("Jean michel");
            players[i].setColor(2);
        } else {
            players[i].setName("Edward");
            players[i].setColor(3);
        }
        setConsoleColor(players[i].getColor());
        cout << "Hi i'm " << players[i].getName() << endl;
        setConsoleColor(7);
    }

};
