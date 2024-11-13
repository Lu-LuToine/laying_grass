#ifndef MENU_H
#define MENU_H
#include "Colors.h"
#include "Player.h"
#include "Game.h"

void startGameName();
int startGameMenu();
void chooseStats(Player players[], int nb_player, Colors chooseColors, Game game);

#endif //MENU_H
