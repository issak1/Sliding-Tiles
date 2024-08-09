class Tile
{
Tile(int value = 0);

  int getValue() const;
  void setValue(int value);
  bool isEmpty() const;

private:
  int value;
}
