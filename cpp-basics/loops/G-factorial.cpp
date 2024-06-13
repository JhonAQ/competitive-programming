#include <iostream>

using namespace std;

double factorial(double k)
{
  if (k == 1)
    return 1;
  return k * factorial(k - 1);
}

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    double k;
    cin >> k;
    cout << factorial(k);
    cout << "\n";
  }
}