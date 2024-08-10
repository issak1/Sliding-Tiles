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
