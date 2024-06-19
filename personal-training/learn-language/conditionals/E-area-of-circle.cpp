#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  const double PI = 3.141592653;
  cout << fixed << setprecision(9);

  double radio;
  cin >> radio;

  cout << (radio * radio) * PI;
}