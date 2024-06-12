#include <iostream>

using namespace std;

bool compare(int left, char symbol, int right)
{
  switch (symbol)
  {
  case '<':
    return left < right;
  case '>':
    return left > right;
  case '=':
    return left == right;
  }
  return false;
}

int main()
{
  int left, right;
  char symbol;

  cin >> left;
  cin >> symbol;
  cin >> right;

  cout << (compare(left, symbol, right) ? "Right" : "Wrong");
}