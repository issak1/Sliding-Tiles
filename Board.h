#include "Tile.h"
#include <vector>

class Board {
public:
    Board(int size);

    void shuffle();
    bool moveTile(int tileValue);
    bool isSolved() const;
    void printBoard() const;
}
