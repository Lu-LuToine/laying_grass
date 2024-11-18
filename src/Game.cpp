#include "../include/Game.h"

#include <algorithm>

#include "../include/Colors.h"
#include "../include/Player.h"
#include "../include/Bonus.h"

#include <iostream>
#include <queue>
#include <random>
#include <vector>

using namespace std;

/*Game Class*/
Game::Game(){
    this->turn = 1;
    this->nbPlayer = 0;
};

// TODO => attention pour finir le jeu on doit faire que 9 turn, on ne doit s pas poser toutes les tuiles !!
void Game::setTurn(int turn){
    this->turn = turn;
};

int Game::getTurn(){
    return this->turn;
};

void Game::setNbPlayer(int nbPlayer){
    this->nbPlayer = nbPlayer;
};

int Game::getNbPlayer(){
    return this->nbPlayer;
};


/*Others Functions*/

bool cardinateStatusCases(Board &board, int x, int y, bool allAndCases, int value) {
    // Check for bonus
    // 4 corners
    if (allAndCases) {
        if(x == 0 && y == 0) {
            if (board.boardStruct[x][y + 1].getStatus() == value && board.boardStruct[x + 1][y].getStatus() == value) {
                return true;
            }
        }

        else if(x == 0 && y == board.getSize()) {
            if (board.boardStruct[x - 1][y].getStatus() == value && board.boardStruct[x][y + 1].getStatus() == value) {
                return true;
            }
        }

        else if(y == 0 && x == board.getSize()) {
            if (board.boardStruct[x][y - 1].getStatus() == value && board.boardStruct[x + 1][y].getStatus() == value) {
                return true;
            }

        }

        else if(x  == board.getSize() && y == board.getSize()) {
            if (board.boardStruct[x - 1][y].getStatus() == value && board.boardStruct[x][y - 1].getStatus() == value) {
                return true;
            }

        }


        // -------------------------------------


        // 4 lines

        // Top line
        else if(x == 0 && y < board.getSize() -1 ) {
            if (board.boardStruct[x][y - 1].getStatus() == value && board.boardStruct[x][y + 1].getStatus() == value && board.boardStruct[x + 1][y].getStatus() == value) {
                return true;
            }

        }

        // Left line
        else if(y == 0 && x < board.getSize() -1 ) {
            if (board.boardStruct[x - 1][y].getStatus() == value && board.boardStruct[x + 1][y].getStatus() == value && board.boardStruct[x][y + 1].getStatus() == value) {
                return true;
            }

        }

        // Bottom line
        else if(y == board.getSize() && x < board.getSize() -1 ) {
            if (board.boardStruct[x][y - 1].getStatus() == value && board.boardStruct[x][y + 1].getStatus() == value && board.boardStruct[x - 1][y].getStatus() == value) {
                return true;
            }

        }

        // Right line
        else if(x == board.getSize() && y < board.getSize() -1 ) {
            if (board.boardStruct[x - 1][y].getStatus() == value && board.boardStruct[x + 1][y].getStatus() == value && board.boardStruct[x][y - 1].getStatus() == value) {
                return true;
            }
        }

        // -------------------------------------


        // Default
        else if(x > 0 && x < board.getSize() - 1 && y > 0 && y < board.getSize() - 1) {
            if (board.boardStruct[x][y + 1].getStatus() == value && board.boardStruct[x + 1][y].getStatus() == value && board.boardStruct[x - 1][y].getStatus() == value && board.boardStruct[x][y - 1].getStatus() == 0) {
                return true;
            }
        }
    // --------------------------------------------------------------------------
    // Check for tiles
    // 4 corners
    } else {
        if(x == 0 && y == 0) {
            if (board.boardStruct[x][y + 1].getStatus() == value || board.boardStruct[x + 1][y].getStatus() == value) {
                return true;
            }
        }

        else if(x == 0 && y == board.getSize()) {
            if (board.boardStruct[x - 1][y].getStatus() == value || board.boardStruct[x][y + 1].getStatus() == value) {
                return true;
            }
        }

        else if(y == 0 && x == board.getSize()) {
            if (board.boardStruct[x][y - 1].getStatus() == value || board.boardStruct[x + 1][y].getStatus() == value) {
                return true;
            }

        }

        else if(x  == board.getSize() && y == board.getSize()) {
            if (board.boardStruct[x - 1][y].getStatus() == value || board.boardStruct[x][y - 1].getStatus() == value) {
                return true;
            }

        }


        // -------------------------------------


        // 4 lines

        // Top line
        else if(x == 0 && y < board.getSize() -1 ) {
            if (board.boardStruct[x][y - 1].getStatus() == value || board.boardStruct[x][y + 1].getStatus() == value || board.boardStruct[x + 1][y].getStatus() == value) {
                return true;
            }

        }

        // Left line
        else if(y == 0 && x < board.getSize() -1 ) {
            if (board.boardStruct[x - 1][y].getStatus() == value || board.boardStruct[x + 1][y].getStatus() == value || board.boardStruct[x][y + 1].getStatus() == value) {
                return true;
            }

        }

        // Bottom line
        else if(y == board.getSize() && x < board.getSize() -1 ) {
            if (board.boardStruct[x][y - 1].getStatus() == value || board.boardStruct[x][y + 1].getStatus() == value || board.boardStruct[x - 1][y].getStatus() == value) {
                return true;
            }

        }

        // Right line
        else if(x == board.getSize() && y < board.getSize() -1 ) {
            if (board.boardStruct[x - 1][y].getStatus() == value || board.boardStruct[x + 1][y].getStatus() == value || board.boardStruct[x][y - 1].getStatus() == value) {
                return true;
            }
        }

        // -------------------------------------


        // Default
        else if(x > 0 && x < board.getSize() - 1 && y > 0 && y < board.getSize() - 1) {
            if (board.boardStruct[x][y + 1].getStatus() == value || board.boardStruct[x + 1][y].getStatus() == value || board.boardStruct[x - 1][y].getStatus() == value || board.boardStruct[x][y - 1].getStatus() == value) {
                return true;
            }
        }
    }


    return false;

}

int convertLetterToCoos(char letter){
    int yco = int(letter);
    cout << "LETTER RESULT" << yco-65 << endl;
    if (yco-65 > 26){
        return yco-71;
    } else {
        return yco-65;
    }
};

void startingPlace(Player players[], Game game, Board &board){
    for (int i = 0; i < game.getNbPlayer(); i++) {
        int x;
        char y;
        int yco;

        setConsoleColor(players[i].getColor());
        cout << "Player " << i+1 << endl;
        setConsoleColor(10);
        cout << "Choose your starting place x (a number) : " << endl;
        cout << "*> ";
        cin >> x;

        cout << "Choose your starting place y (a letter) : " << endl;
        cout << "*> ";
        cin >> y;
        yco = convertLetterToCoos(y);

        if (0 > x || x > board.getSize() || 65 > int(y) || int(y) > 84 || !cardinateStatusCases(board, x, yco, true, 0)){ // Check if x and y are correct
            do {
                setConsoleColor(79);
                board.getSize() == 20 ? cout << "[ERROR] - Chose a valid X position (between 0 and 20)" << endl : cout << "[ERROR] - Chose a valid X position (between 0 and 30)" << endl;
                setConsoleColor(10);
                cout << "Choose your starting place x (a number) : " << endl;
                cout << "*> ";
                cin >> x;

                setConsoleColor(79);
                board.getSize() == 20 ? cout << "[ERROR] - Chose a valid Y position (between A and T)" << endl : cout << "[ERROR] - Chose a valid Y position (between A and d)" << endl;
                setConsoleColor(10);
                cout << "Choose your starting place y (a number) : " << endl;
                cout << "*> ";
                cin >> y;
                yco = convertLetterToCoos(y);
            } while (0 > x || x > board.getSize() || 65 > int(y) || int(y) > 84 || !cardinateStatusCases(board, x, yco, true, 0));
        }

        yco = convertLetterToCoos(y);
        players[i].setBeginPlace(x, yco);
        cout << "Player " << i + 1 << " start at x " <<  players[i].getBeginPlace().first << " and y " << players[i].getBeginPlace().second << endl;

        board.boardStruct[x][yco] = Cells();
        board.boardStruct[x][yco].setStatus(i + 1);
        players[i].setCells(x, yco);
        players[i].getCells();

        board.getBoard(players);
    }
}

void bonusCaptured(Game &game, Board &board, Bonus bonus[], Player players[], int bonusSize) {
    for(int i = 0; i < bonusSize; i++) {
        for(int k = 1; k < game.getNbPlayer(); k++) {
            if(cardinateStatusCases(board, bonus[i].getPosition().first, bonus[i].getPosition().first, true, k)) {
                bonus[i].setPlayer(k);
                players[k].setBonus(bonus[i].getType());
            }
        }
    }
}

void gameLoop(Game &game, Board &board, Bonus bonus[], Player players[], Tiles &tiles, int totalBonuses) {
    // Loop until the desired number of turns has been reached
    while (game.getTurn() < 3) {
        // Each player plays during the same turn
        for (int i = 0; i < game.getNbPlayer(); i++) {
            int playerX;
            int playerY;
            int action;

            bool turnComplete = false;

            while (!turnComplete) {
                cout << "PLAYER " << i + 1 << " || " << players[i].getName() << endl;
                cout << "DEBUG - What do ? :" << endl;
                cout << "DEBUG - 0 Placement" << endl;
                cout << "DEBUG - 1 Rotate" << endl;
                cout << "DEBUG - 2 Flip" << endl;
                cout << "DEBUG - 3 Power-Up" << endl;
                cin >> action;

                switch (action) {
                    case 0:
                        cout << "DEBUG - placement de la tuile : x :" << endl;
                        cin >> playerX;
                        cout << "DEBUG - placement de la tuile : y :" << endl;
                        cin >> playerY;

                        // If the placement is valid, end the turn
                        if (tiles.placeFormInBoard(board, playerX, playerY, i + 1, players)) {
                            board.getBoard(players);
                            bonusCaptured(game, board, bonus, players, totalBonuses);
                            for (int j = 0; j < totalBonuses; j++) {
                                bonus[j].debug();
                            }
                            tiles.displayQueueForm();
                            turnComplete = true;  // End the current player's turn
                        } else {
                            cout << "[ERROR] - Invalid placement, try again." << endl;
                        }
                        break;

                    case 1:
                        tiles.rotateForm();
                        tiles.displayCurrentTile();
                        break;

                    case 2:
                        tiles.flipForm();
                        cout << "fliped" << endl;
                        tiles.displayCurrentTile();
                        break;

                    case 3:
                        cout << "You have " << players[i].getBonus().size() << " Power-Up(s)" << endl;
                        for (int bonusCount = 0; bonusCount < players[i].getBonus().size(); bonusCount++) {
                            cout << bonusCount << " : " << players[i].getBonus()[bonusCount] << endl;
                        }

                        int powerUp;
                        cout << "Select a bonus : ";
                        cin >> powerUp;

                        if (powerUp < players[i].getBonus().size()) {
                            cout << "bonus";
                            tiles.tileExchange();
                            tiles.displayQueueForm();
                            players[i].deleteBonus(powerUp);
                            //TODO SET USE TO TRUE
                            //bonus[i].setUsed(true);
                        } else {
                            cout << "[ERROR] - Invalid selection." << endl;
                        }
                        break;

                    default:
                        cout << "[ERROR] - Unrecognized action" << endl;
                        break;
                }
            }
        }

        game.setTurn(game.getTurn() + 1);
        cout << "Turn " << game.getTurn() << endl;
        if (game.getTurn() == 3) {
            for (int i = 0; i < game.getNbPlayer(); i++) {
            }
                game.endGameCalculTerritory(players, board);
        }

    }
}

void Game::endGameCalculTerritory(Player players[], Board &board) {
    vector<pair<int, int>> allPlayerSize;

    for (int k = 0; k < getNbPlayer(); k++) {
        std::cout << "player " << k << std::endl;
        vector<pair<int, int>> cells = players[k].getCells();
        vector<int> currentPlayerSizes;

        int xMin;
        int yMin;
        int xMax;
        int yMax;

        for (const auto &cell : cells) {
            xMin = min(xMin, cell.first);
            yMin = min(yMin, cell.second);
            xMax = max(xMax, cell.first);
            yMax = max(yMax, cell.second);
        }

        std::cout << "xMin, xMax, yMin, yMax: " << xMin << " " << xMax << " " << yMin  << " " << yMax << std::endl;

        for (int i = xMin; i < xMax; i++) {
            for (int j = yMin; j < yMax; j++) {
                double totalCases = 0;

                if(i + 1 < board.boardStruct.size() && j + 1 < board.boardStruct[0].size() &&
                   board.boardStruct[i][j].getStatus() == k + 1 &&
                   board.boardStruct[i+1][j].getStatus() == k + 1 &&
                   board.boardStruct[i][j+1].getStatus() == k + 1 &&
                   board.boardStruct[i+1][j+1].getStatus() == k + 1)
                {
                    std::cout << "hi from if" << std::endl;
                    totalCases += 1;

                    while (i + 2 < board.boardStruct.size() && j + 2 < board.boardStruct[0].size() &&
                        board.boardStruct[i+1][j+1].getStatus() == k + 1 &&
                        board.boardStruct[i+2][j+1].getStatus() == k + 1 &&
                        board.boardStruct[i+1][j+2].getStatus() == k + 1 &&
                        board.boardStruct[i+2][j+2].getStatus() == k + 1)
                    {
                        totalCases += 0.5;
                        i += 2;
                        j += 2;
                        std::cout << "hi from else" << std::endl;
                    }

                    std::cout << "TOTAL CASES before 2: " << totalCases << std::endl;
                    totalCases = totalCases * 2;
                    std::cout << "TOTAL CASES: " << totalCases << std::endl;
                    currentPlayerSizes.push_back(int(totalCases));
                }
            }
        }

        if (!currentPlayerSizes.empty()) {
            int maxSize = *max_element(currentPlayerSizes.begin(), currentPlayerSizes.end());
            allPlayerSize.emplace_back(k, maxSize);
        } else {
            allPlayerSize.emplace_back(k, 0);
        }

        currentPlayerSizes.clear();
    }

    std::cout << "All players' territories: ";
    for (const auto &size : allPlayerSize) {
        std::cout << "(" << size.first << ", " << size.second << ") ";
    }
    std::cout << std::endl;

    auto maxIt = max_element(allPlayerSize.begin(), allPlayerSize.end(),
                               [](const pair<int, int>& a, const pair<int, int>& b) {
                                   return a.second < b.second;
                               });
    size_t winnerIndex = maxIt->first;  // Player ID of the winner
    std::cout << "== WINNER IS Player " << winnerIndex + 1 << " with " << maxIt->second << " territory points." << std::endl;

}


Game::~Game(){};
