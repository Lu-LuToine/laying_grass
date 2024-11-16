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

void Tiles::setForm(Game game) {
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
    int formWidth = this->form.size();
    int formHeight = this->form[0].size();

    std::cout << formWidth << std::endl;

    if (player_x < 0 || player_y < 0 || player_x + formHeight > boardSize || player_y + formWidth > boardSize || player_x + formHeight < 0 || player_y + formWidth < 0) {
        std::cout << "Error: out of range" << std::endl;
        return false;
    } else {
        // Keep original status
        std::vector<std::vector<int>> originalStatuses(formWidth, std::vector<int>(formHeight));

        for (int i = 0; i < formWidth; i++) {
            for (int j = 0; j < formHeight; j++) {
                if (this->form[i][j] == 1) {
                    int status = board.boardStruct[player_x + i][player_y + j].getStatus();

                    originalStatuses[i][j] = status;

                    if (status != 0 && status != 10 && status != 11 && status != 12) {
                        isCompatible = false;
                        std::cout << "Error: can't place at (" << player_x << ", " << player_y << ") invalid position." << std::endl;
                        break;
                    }
                }
            }
            if (!isCompatible) break;
        }

        if (isCompatible) {
            for (int i = 0; i < formWidth; i++) {
                for (int j = 0; j < formHeight; j++) {
                    if (this->form[i][j] == 1) {
                        board.boardStruct[player_x + i][player_y + j].setStatus(currentPlayer);
                    }
                }
            }

            int user_confirm;
            board.getBoard(player);

            do {
                std::cout << "Would you confirm your position? - 1 yes | 2 no" << std::endl;
                std::cin >> user_confirm;
            } while (user_confirm != 1 && user_confirm != 2);

            if (user_confirm == 2) {
                for (int i = 0; i < formWidth; i++) {
                    for (int j = 0; j < formHeight; j++) {
                        if (this->form[i][j] == 1) {
                            board.boardStruct[player_x + i][player_y + j].setStatus(originalStatuses[i][j]);
                        }
                    }
                }
                std::cout << "Position cancelled. Try another position." << std::endl;
                return false;
            }

            if (currentPlayer == 1) {
                allForms.erase(allForms.begin());
                this->player = currentPlayer;
                std::cout << this->name << " " << this->player << std::endl;
                return true;
            } else {
                return false;
            }

        } else {
            std::cout << "Current tile can't be placed here, nothing happened, try another position" << std::endl;
            return false;
        }
    }
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

