#include "Board.h"
#include <iostream>

int main()
{
  int size = 3;
  Board board(size);
  
  board.shuffle();

  while(!board.isSolved())
    {
      board.printBoard();

      int move;
      std::cout << "Enter tile number to move: ";
      std::cin >> move;

      if (!board.moveTile(move))
      {
        std::cout << "Invalid move!" << std::endl;
      }
    }
  std::cout << "Congratulations, you have solved the puzzle" << std::endl;
}
