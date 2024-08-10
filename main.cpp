#include "Board.h"
#include <iostream>

int main()
{
  int size;

  std::cout << "Enter the size of the board (e.g., 3 for a 3x3 board): ";
  std::cin >> size;

  while (size < 2) 
  {
    std::cout << "Invalid size. The board must be at least 2x2. Please enter a valid size: ";
    std::cin >> size;
  }
  
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

  return 0;
}
