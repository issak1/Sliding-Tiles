#include "Tile.h"

Tile::Tile(int value) : value(value)) {}

int Tile::getValue() const 
{
  return value;
}

void Title::setValue(int value)
{
  this->value = value;
}

bool Title::isEmpty() const 
{
  return value == 0;
}
