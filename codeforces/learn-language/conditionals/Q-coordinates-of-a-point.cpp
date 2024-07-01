#include <iostream>

using namespace std;

int main()
{
  double x, y;
  cin >> x >> y;
  if (x == 0 && y == 0)
  {
    cout << "Origem";
    return 0;
  }
  if (x == 0)
  {
    cout << "Eixo Y";
    return 0;
  }
  if (y == 0)
  {
    cout << "Eixo X";
    return 0;
  }

  bool xs = x > 0;
  bool ys = y > 0;

  if (xs && ys)
  {
    cout << "Q1";
  }
  if (xs && !ys)
  {
    cout << "Q4";
  }
  if (!xs && ys)
  {
    cout << "Q2";
  }

  if (!xs && !ys)
  {
    cout << "Q3";
  }
}