#include "Tile.h"
#include <vector>

class Board {
public:
    Board(int size);

    void shuffle();
    bool moveTile(int tileValue);
    bool isSolved() const;
    void printBoard() const;

private:
    int size;
    std::vector<std::vector<Tile>> grid;

    void swapTiles(int x1, int y1, int x2, int y2);
    bool isAdjacent(int x1, int y1, int x2, int y2) const;
};

}
