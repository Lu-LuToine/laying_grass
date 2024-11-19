#include "../include/Game.h"
#include "../include/Colors.h"
#include "../include/Player.h"
#include "../include/Bonus.h"

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>


using namespace std;

/*Game Class*/
Game::Game(){
    this->turn = 1;
    this->nbPlayer = 0;
};

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
            if (board.boardStruct[x][y + 1].getStatus() == value && board.boardStruct[x + 1][y].getStatus() == value && board.boardStruct[x - 1][y].getStatus() == value && board.boardStruct[x][y - 1].getStatus() == value) {
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
        cout << "[INIT] - Choose your starting place x (a number) : " << endl;
        cout << "*> ";
        cin >> x;

        cout << "[INIT] - Choose your starting place y (a letter) : " << endl;
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
                cout << "Choose your starting place y (a letter) : " << endl;
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
    }
}

void bonusCaptured(Game &game, Board &board, Bonus bonus[], Player players[], int bonusSize) {
    for(int i = 0; i < bonusSize; i++) {
        for(int k = 0; k < game.getNbPlayer(); k++) {
            if(bonus[i].getPlayer() == 0) {
                if(cardinateStatusCases(board, bonus[i].getPosition().first, bonus[i].getPosition().second, true, k + 1)){
                    int bonusType = bonus[i].getType();  // Get the type of the bonus

                    if (bonusType >= 0) {
                        players[k].setBonus(bonusType);
                        std::cout << "Nice ! Player " << k + 1 << " received bonus: " << bonus[i].getName() << std::endl;
                        bonus[i].setPlayer(k + 1);
                        board.boardStruct[bonus[i].getPosition().first][bonus[i].getPosition().second].setPlayer(k + 1);
                    }

                    if(bonus[i].getType() == 1) {
                        stonePowerUp(board);
                    }
                }
            }
        }
    }
}




void gameLoop(Game &game, Board &board, Bonus bonus[], Player players[], Tiles &tiles, int totalBonuses) {
    while (game.getTurn() < 9) {
        for (int i = 0; i < game.getNbPlayer(); i++) {
            int playerX;
            char playerY;
            int  playerYint;
            int action;

            bool turnComplete = false;

            while (!turnComplete) {
                do {
                    cout << "== PLAYER " << i + 1 << " || " << players[i].getName() << endl;
                    cout << "[Play] - Choose your next action ? :" << endl;
                    cout << "0 - Placement" << endl;
                    cout << "1 - Rotate" << endl;
                    cout << "2 - Flip" << endl;
                    cout << "3 - Power-Up" << endl;
                    cout << "4 - Blocked ? pass" << endl;
                    cout << "*> ";
                    cin >> action;
                } while (0 > action && action > 4);

                switch (action) {
                    case 0:
                        cout << "[Tiles] - Set x for your tile (a number) : " << endl;
                        cout << "*> " << endl;
                        cin >> playerX;
                        cout << "[Tiles] - Set y for your tile (a letter) : " << endl;
                        cout << "*> ";
                        cin >> playerY;

                        if (0 > playerX || playerX > board.getSize() || 65 > int(playerY) || int(playerY) > 84){
                            do {
                                setConsoleColor(79);
                                board.getSize() == 20 ? cout << "[ERROR] - Chose a valid X position (between 0 and 20)" << endl : cout << "[ERROR] - Chose a valid X position (between 0 and 30)" << endl;
                                setConsoleColor(10);
                                cout << "[Tiles] - Choose your starting place x (a number) : " << endl;
                                cout << "*> ";
                                cin >> playerX;

                                setConsoleColor(79);
                                board.getSize() == 20 ? cout << "[ERROR] - Chose a valid Y position (between A and T)" << endl : cout << "[ERROR] - Chose a valid Y position (between A and d)" << endl;
                                setConsoleColor(10);
                                cout << "[Tiles] - Choose your starting place y (a letter) : " << endl;
                                cout << "*> ";
                                cin >> playerY;
                            } while (0 > playerX || playerX > board.getSize() || 65 > int(playerY) || int(playerY) > 84);
                        }

                        playerYint = convertLetterToCoos(playerY);


                        // If the placement is valid, end the turn
                        if (tiles.placeFormInBoard(board, playerX, playerYint, i + 1, players)) {
                            bonusCaptured(game, board, bonus, players, totalBonuses);
                            tiles.displayQueueForm();
                            turnComplete = true;  // End the current player's turn
                        } else {
                            cout << "[ERROR] - Invalid placement, try again." << endl;
                        }
                        break;

                    case 1:
                        tiles.rotateForm();
                        cout << "[Tiles] - Tile rotated !" << endl;
                        tiles.displayCurrentTile();
                        break;

                    case 2:
                        tiles.flipForm();
                        cout << "[Tiles] - Tile flipped !" << endl;
                        tiles.displayCurrentTile();
                        break;

                    case 3:
                        cout << "[Bonus] - You have " << players[i].getBonus().size() << " Power-Up(s)" << endl;
                        if (players[i].getBonus().size() > 0) {
                            for (int bonusCount = 0; bonusCount < players[i].getBonus().size(); bonusCount++) {
                                cout << bonusCount << " : " << "Tile exchange" << endl;
                            }

                            int powerUp;
                            do {
                                cout << "[Bonus] - Select a bonus : ";
                                cout << "*> ";
                                cin >> powerUp;
                            } while(powerUp < 0);


                            if (powerUp < players[i].getBonus().size()) {
                                tiles.tileExchange(board);
                                tiles.displayQueueForm();
                                players[i].deleteBonus(powerUp);
                            } else {
                                cout << "[ERROR] - Invalid selection." << endl;
                            }
                        }
                        break;

                    case 4:
                        cout << "Blocked - next player  : ";
                        turnComplete = true;
                        break;

                    default:
                        cout << "[ERROR] - Unrecognized action" << endl;
                        break;
                }
            }
            board.getBoard(players);
            tiles.displayQueueForm();
            bonusCaptured(game, board, bonus, players, totalBonuses);
        }

        game.setTurn(game.getTurn() + 1);
        cout << "=== Turn " << game.getTurn() << " ===" << endl;
        if (game.getTurn() == 10) {
            for (int i = 0; i < game.getNbPlayer(); i++) {
                for (int bonusCount = 0; bonusCount < players[i].getBonus().size(); bonusCount++) {
                    if (!players[i].getBonus().empty()) {
                        cout << "== PLAYER " << i + 1 << " || " << players[i].getName() << endl;
                        finalTileExchange(board, i);
                    };
                }

            }
                game.endGameCalculTerritory(players, board);
        }

    }
}

void Game::endGameCalculTerritory(Player players[], Board &board) {
    vector<pair<int, int>> allPlayerSize;

    for (int k = 0; k < getNbPlayer(); k++) {
        vector<pair<int, int>> cells = players[k].getCells();
        vector<int> currentPlayerSizes;

        int xMin = 0;
        int yMin = 0;
        int xMax = 0;
        int yMax = 0;

        for (const auto &cell : cells) {
            xMin = min(xMin, cell.first);
            yMin = min(yMin, cell.second);
            xMax = max(xMax, cell.first);
            yMax = max(yMax, cell.second);
        }

        for (int i = xMin; i < xMax; i++) {
            for (int j = yMin; j < yMax; j++) {
                double totalCases = 0;

                if(i + 1 < board.boardStruct.size() && j + 1 < board.boardStruct[0].size() &&
                   board.boardStruct[i][j].getStatus() == k + 1 &&
                   board.boardStruct[i+1][j].getStatus() == k + 1 &&
                   board.boardStruct[i][j+1].getStatus() == k + 1 &&
                   board.boardStruct[i+1][j+1].getStatus() == k + 1)
                {
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
                    }
                    totalCases = totalCases * 2;
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

    std::cout << "[FINAL] - GAME'S STATISTIC : " << endl;
    for (const auto &size : allPlayerSize) {
        setConsoleColor(players[size.first].getColor());
        std::cout << "- Player " << size.first + 1 << " - " << players[size.first].getName() << " : " << size.second  << "*" << size.second << std::endl;
    }
    std::cout << std::endl;

    int maxScore = max_element(allPlayerSize.begin(), allPlayerSize.end(),
                               [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                                   return a.second < b.second;
                               })->second;

    std::vector<int> winners;
    for (const auto& size : allPlayerSize) {
        if (size.second == maxScore) {
            winners.push_back(size.first);
        }
    }

    if (winners.size() == 1) {
        setConsoleColor(96);
        std::cout << "== WINNER IS Player " << winners[0] + 1 << " - " << players[winners[0]].getName() << " with " << maxScore << "*" << maxScore << " territory point !!" << std::endl;
    } else {
        setConsoleColor(111);
        std::cout << "== IT'S A TIE! Calculating winner ... " << std::endl;
        vector<pair<int, int>> tieMaxSize;
        for (size_t i = 0; i < winners.size(); ++i) {
            int playerIndex = winners[i];
            tieMaxSize.push_back(std::make_pair(playerIndex, players[playerIndex].getCells().size()));
        }
        auto maxElement = std::max_element(
               tieMaxSize.begin(),
               tieMaxSize.end(),
               [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                   return a.second < b.second;
               }
           );
        int finalWinner = maxElement->first;
        setConsoleColor(96);
        std::cout << "== WINNER IS Player " << finalWinner + 1 << " - " << players[finalWinner].getName() << " with " << maxScore << "*" << maxScore << " territory point !!" << std::endl;
    }
    setConsoleColor(7);
}


Game::~Game(){};

void stonePowerUp(Board &board){

    int cosx;
    char cosy;

    cout << "[Tiles] - Set x for your tile (a number) : " << endl;
    cout << "*> " << endl;
    cin >> cosx;
    cout << "[Tiles] - Set y for your tile (a letter) : " << endl;
    cout << "*> " << endl;
    cin >> cosy;

    if (0 > cosx || cosx > board.getSize() || 65 > int(cosy) || int(cosy) > 84){
        do {
            setConsoleColor(79);
            board.getSize() == 20 ? cout << "[ERROR] - Chose a valid X position (between 0 and 20)" << endl : cout << "[ERROR] - Chose a valid X position (between 0 and 30)" << endl;
            setConsoleColor(10);
            cout << "[Tiles] - Choose your starting place x (a number) : " << endl;
            cout << "*> ";
            cin >> cosx;

            setConsoleColor(79);
            board.getSize() == 20 ? cout << "[ERROR] - Chose a valid Y position (between A and T)" << endl : cout << "[ERROR] - Chose a valid Y position (between A and d)" << endl;
            setConsoleColor(10);
            cout << "[Tiles] - Choose your starting place y (a letter) : " << endl;
            cout << "*> ";
            cin >> cosy;
        } while (0 > cosx || cosy > board.getSize() || 65 > int(cosy) || int(cosy) > 84);
    }

    int cosyint = convertLetterToCoos(cosy);

    board.boardStruct[cosx][cosyint].setStatus(13);

};

void finalTileExchange(Board &board, int playerStatus) {
    int cosx;
    char cosy;

    cout << "[Tiles] - Set x for your tile (a number) : " << endl;
    cout << "*> " << endl;
    cin >> cosx;
    cout << "[Tiles] - Set y for your tile (a letter) : " << endl;
    cout << "*> " << endl;
    cin >> cosy;

    if (0 > cosx || cosx > board.getSize() || 65 > int(cosy) || int(cosy) > 84){
        do {
            setConsoleColor(79);
            board.getSize() == 20 ? cout << "[ERROR] - Chose a valid X position (between 0 and 20)" << endl : cout << "[ERROR] - Chose a valid X position (between 0 and 30)" << endl;
            setConsoleColor(10);
            cout << "[Tiles] - Choose your starting place x (a number) : " << endl;
            cout << "*> ";
            cin >> cosx;

            setConsoleColor(79);
            board.getSize() == 20 ? cout << "[ERROR] - Chose a valid Y position (between A and T)" << endl : cout << "[ERROR] - Chose a valid Y position (between A and d)" << endl;
            setConsoleColor(10);
            cout << "[Tiles] - Choose your starting place y (a letter) : " << endl;
            cout << "*> ";
            cin >> cosy;
        } while (0 > cosx || cosy > board.getSize() || 65 > int(cosy) || int(cosy) > 84);
    }

    int cosyint = convertLetterToCoos(cosy);

    board.boardStruct[cosx][cosyint].setStatus(playerStatus+1);
}

