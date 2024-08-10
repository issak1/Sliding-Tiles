#include "Board.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

Board::Board(int size) : size(size), grid(size, std::vector<Tile>(size)) {
    int value = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size - 1 && j == size - 1) {
                grid[i][j] = Tile(0); // empty tile
            }
            else {
                grid[i][j] = Tile(value++);
            }
        }
    }
}

void Board::shuffle() {
    std::vector<int> values;
    for (int i = 0; i < size * size; ++i) {
        values.push_back(i);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(values.begin(), values.end(), std::default_random_engine(seed));

    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j].setValue(values[index++]);
        }
    }
}

bool Board::moveTile(int tileValue) {
    int emptyX = -1, emptyY = -1, tileX = -1, tileY = -1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j].isEmpty()) {
                emptyX = i;
                emptyY = j;
            }
            if (grid[i][j].getValue() == tileValue) {
                tileX = i;
                tileY = j;
            }
        }
    }

    if (isAdjacent(emptyX, emptyY, tileX, tileY)) {
        swapTiles(emptyX, emptyY, tileX, tileY);
        return true;
    }

    return false;
}

bool Board::isSolved() const {
    int value = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size - 1 && j == size - 1) {
                if (!grid[i][j].isEmpty()) return false;
            }
            else if (grid[i][j].getValue() != value++) {
                return false;
            }
        }
    }
    return true;
}

void Board::printBoard() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j].isEmpty()) {
                std::cout << "   ";
            }
            else {
                std::cout << grid[i][j].getValue() << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::swapTiles(int x1, int y1, int x2, int y2) {
    std::swap(grid[x1][y1], grid[x2][y2]);
}

bool Board::isAdjacent(int x1, int y1, int x2, int y2) const {
    return (x1 == x2 && abs(y1 - y2) == 1) || (y1 == y2 && abs(x1 - x2) == 1);
}
