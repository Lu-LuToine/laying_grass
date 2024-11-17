#include "../include/Tiles.h"

#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

#include "../include/Game.h"

std::vector<Tiles> Tiles::allForms;

Tiles::Tiles(){
    this->name =  "";
    this->player = 0;
    this->rotation = 0;
    this->letters = 'a';
    this->flip = false;
    this->form;
};

void Tiles::setPlayer(int player){
    this->player = player;
};

int Tiles::getPlayer() const{
    return this->player;
};

void Tiles::setLetters() {
}

char Tiles::getLetters() const {
    return this->letters;
}

void Tiles::setRotation(int rotation){
    this->rotation = rotation;
};

int Tiles::getRotation() const{
    return this->rotation;
};

void Tiles::setFlip(bool flip){
    this->flip = flip;
};

bool Tiles::getFlip() const{
    return this->flip;
};

void Tiles::setForm(Game &game) {
    int count = 97;
    allForms.clear();

    for (int i = 1; i < count; i++) {
        std::string filename = "../tiles/tile" + std::to_string(i) + ".txt";
        std::vector<std::vector<int>> shape;
        std::ifstream file(filename);
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::vector<int> row;
                for (char c : line) {
                    if (c == '*') {
                        row.push_back(1);
                    } else if (c == '.') {
                        row.push_back(0);
                    }
                }
                shape.push_back(row);
            }
            file.close();
        } else {
            std::cerr << "Error - can't open this file : " << filename << std::endl;
        }

        Tiles tile;
        tile.name = "tile" + std::to_string(i);
        tile.form = shape;
        allForms.push_back(tile);
    }

    // Shuffle allForms ; adapt to get different result every time restart game
    srand(time(0));
    std::default_random_engine engine(static_cast<unsigned int>(time(0)));

    std::shuffle(allForms.begin(), allForms.end(), engine);

    // Set number of tiles to suit of number of players
    int nbPlayers = game.getNbPlayer() ;
    int nbTiles = round(10.67 * nbPlayers);
    int nbTilesToRemove = allForms.size() - nbTiles;

    for (int i = 0; i < nbTilesToRemove; ++i) {
        allForms.pop_back();
    }
}

void Tiles::debugDisplayAllForms() {
    for (size_t i = 0; i < allForms.size(); ++i) {
        const Tiles& tile = allForms[i];
        std::cout << "Tile " << i << " (" << tile.name << "):" << std::endl;

        for (const auto& row : tile.form) {
            for (int cell : row) {
                std::cout << (cell == 1 ? char(219) : ' ');
            }
            std::cout << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }
}

std::vector<std::vector<int>> Tiles::rotate90(const std::vector<std::vector<int>>& matrice) const {
    if (matrice.empty() || matrice[0].empty()) {
        std::cerr << "Error : can't rotate this tiles\n";
        return matrice;
    }

    int rows = matrice.size();
    int cols = matrice[0].size();
    std::vector<std::vector<int>> rotated(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[j][rows - i - 1] = matrice[i][j];
        }
    }
    return rotated;
}

bool Tiles::isSameShape(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) const {
    return a == b;
}

void Tiles::rotateForm() {
    std::vector<std::vector<int>> currentForm = this->form;

    std::vector<std::vector<int>> rotatedForm = rotate90(currentForm);

    if (!isSameShape(currentForm, rotatedForm)) {
        this->form = rotatedForm;
    }
}

void Tiles::displayCurrentTile() {
    size_t maxHeight = this->form.size();
    size_t maxWidth = 0;

    for (const auto& row : this->form) {
        maxWidth = std::max(maxWidth, row.size());
    }

    for (size_t row = 0; row < maxHeight; ++row) {
        for (size_t col = 0; col < maxWidth; ++col) {
            if (col < this->form[row].size()) {
                std::cout << (this->form[row][col] == 1 ? char(219) : ' ');
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Tiles::placeFormInBoard(Board &board, int player_x, int player_y, int currentPlayer, Player player[]) {
    bool isCompatible = true;

    int boardSize = board.getSize();
    int formWidth = this->form[0].size();
    int formHeight = this->form.size();

    std::cout << "Form dimensions: Width = " << formWidth << ", Height = " << formHeight << ", currentPlayer = " << currentPlayer << std::endl;

    // Found first 1 on y =0
    int startRow = -1;
    for (int i = 0; i < formHeight; ++i) {
        if (this->form[i][0] == 1) {
            startRow = i;
            break;
        }
    }

    int adjustedX = player_x;
    int adjustedY = player_y;

    if (adjustedX - startRow < 0 || adjustedY < 0 || (adjustedX - startRow) + formHeight > boardSize || adjustedY + formWidth > boardSize) {
        std::cout << "Error: out of range" << std::endl;
        return false;
    }

    adjustedX -= startRow;

    std::vector<std::vector<int>> originalStatuses(formHeight, std::vector<int>(formWidth));

    // Check status
    for (int i = 0; i < formHeight; i++) {
        for (int j = 0; j < formWidth; j++) {
            if (this->form[i][j] == 1) {
                int status = board.boardStruct[adjustedX + i][adjustedY + j].getStatus();
                originalStatuses[i][j] = status;

                if (status != 0 && status != 10 && status != 11 && status != 12) {
                    isCompatible = false;
                    std::cout << "Error: can't place at (" << adjustedX + i << ", " << adjustedY + j << ") invalid position." << std::endl;
                    break;
                }
            }
        }
        if (!isCompatible) break;
    }

    if (isCompatible) {
        // Set temporary status to 14 in order to check cardinate point if is current player territory
        for (int i = 0; i < formHeight; i++) {
            for (int j = 0; j < formWidth; j++) {
                if (this->form[i][j] == 1) {
                    board.boardStruct[adjustedX + i][adjustedY + j].setStatus(14); // Temporary status
                }
            }
        }

        bool isAdjacentToPlayer = false;

        for (int i = 0; i < formHeight; i++) {
            for (int j = 0; j < formWidth; j++) {
                if (this->form[i][j] == 1) {
                    int nx = adjustedX + i;
                    int ny = adjustedY + j;

                    // Check if next to player's cell
                    if (cardinateStatusCases(board, nx, ny, false, currentPlayer)) {
                        isAdjacentToPlayer = true;
                        break;
                    }
                }
                if (isAdjacentToPlayer) break;
            }
            if (isAdjacentToPlayer) break;
        }


        if (!isAdjacentToPlayer) {
            std::cout << "Error: no adjacent tile of current player found. The form can't be placed." << std::endl;

            // Restore original status if failed
            for (int i = 0; i < formHeight; i++) {
                for (int j = 0; j < formWidth; j++) {
                    if (this->form[i][j] == 1) {
                        board.boardStruct[adjustedX + i][adjustedY + j].setStatus(originalStatuses[i][j]);
                    }
                }
            }
            return false;
        }

        for (int i = 0; i < formHeight; i++) {
            for (int j = 0; j < formWidth; j++) {
                if (this->form[i][j] == 1) {
                    // Set current player status if success
                    if (board.boardStruct[adjustedX + i][adjustedY + j].getStatus() == 14) {
                        board.boardStruct[adjustedX + i][adjustedY + j].setStatus(currentPlayer);
                    }
                }
            }
        }

        // Check cardinate point
        for (int i = 0; i < formHeight; i++) {
            for (int j = 0; j < formWidth; j++) {
                if (this->form[i][j] == 1) {
                    bool checkResult = cardinateStatusCases(board, adjustedX + i, adjustedY + j, false, currentPlayer);
                    if (!checkResult) {
                        // If failed => rollback
                        for (int rollbackI = 0; rollbackI < formHeight; rollbackI++) {
                            for (int rollbackJ = 0; rollbackJ < formWidth; rollbackJ++) {
                                if (this->form[rollbackI][rollbackJ] == 1) {
                                    board.boardStruct[adjustedX + rollbackI][adjustedY + rollbackJ].setStatus(originalStatuses[rollbackI][rollbackJ]);
                                }
                            }
                        }
                        std::cout << "Error: condition failed for the case at (" << adjustedX + i << ", " << adjustedY + j << "). Position rolled back." << std::endl;
                        return false;
                    }
                }
            }
        }

        // Confirm position
        board.getBoard(player);
        int user_confirm;
        do {
            std::cout << "Would you confirm your position? - 1 yes | 2 no" << std::endl;
            std::cin >> user_confirm;
        } while (user_confirm != 1 && user_confirm != 2);

        if (user_confirm == 2) {
            // Rollback if refused
            for (int i = 0; i < formHeight; i++) {
                for (int j = 0; j < formWidth; j++) {
                    if (this->form[i][j] == 1) {
                        board.boardStruct[adjustedX + i][adjustedY + j].setStatus(originalStatuses[i][j]);
                    }
                }
            }
            std::cout << "Position cancelled. Try another position." << std::endl;
            return false;
        }

        if (user_confirm == 1) {
            allForms.erase(allForms.begin());
            this->player = currentPlayer;
            std::cout << this->name << " " << this->player << std::endl;
            return true;
        }
    } else {
        std::cout << "Current tile can't be placed here, nothing happened, try another position" << std::endl;
        return false;
    }

    return false;
}



void Tiles::displayQueueForm() {
    size_t maxHeight = 0;
    size_t formsToDisplay = std::min(allForms.size(), size_t(5));

    for (size_t i = 0; i < formsToDisplay; ++i) {
        maxHeight = std::max(maxHeight, allForms[i].form.size());
    }
    if (!allForms.empty()) {
        this->form = allForms[0].form;
    }

    std::cout << "Current tile : " << std::endl;
    for (size_t row = 0; row < maxHeight; ++row) {
        for (size_t i = 0; i < 1; ++i) {
            const auto& tile = allForms[i];

            if (row < tile.form.size()) {
                for (int val : tile.form[row]) {
                    std::cout << (val ? char(219) : ' ');
                }
            } else {
                for (size_t col = 0; col < tile.form[0].size(); ++col) {
                    std::cout << ' ';
                }
            }

            std::cout << "  ";
        }
        std::cout << '\n';
    }

    std::cout << "Next tiles - remain " << allForms.size() << " tiles : " << std::endl;
    for (size_t row = 0; row < maxHeight; ++row) {
        for (size_t i = 1; i < formsToDisplay; ++i) {
            const auto& tile = allForms[i];

            if (row < tile.form.size()) {
                for (int val : tile.form[row]) {
                    std::cout << (val ? char(219) : ' ');
                }
            } else {
                for (size_t col = 0; col < tile.form[0].size(); ++col) {
                    std::cout << ' ';
                }
            }

            std::cout << "  ";
        }
        std::cout << '\n';
    }
}



std::vector<std::vector<int>> Tiles::getForm() const {
    return this->form;
}

Tiles::~Tiles(){
};

