#include <iostream>

using namespace std;

int max(int a, int b, int c)
{
  int max = a;

  if (b > max)
    max = b;
  if (c > max)
    max = c;

  return max;
}

int min(int a, int b, int c)
{
  int min = a;
  if (b < min)
    min = b;
  if (c < min)
    min = c;
  return min;
}

int main()
{
  int a, b, c;

  cin >> a >> b >> c;

  cout << min(a, b, c) << ' ' << max(a, b, c);
}
