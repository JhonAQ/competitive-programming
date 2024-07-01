#include <iostream>

using namespace std;

int twoLast(long long n)
{
  return n % 100;
}

int main()
{
  int a, b, c, d;

  cin >> a >> b >> c >> d;

  a = twoLast(a);
  b = twoLast(b);
  c = twoLast(c);
  d = twoLast(d);

  int result = twoLast(a * b * c * d);

  if (result < 10)
    cout << 0;
  cout << twoLast(a * b * c * d);
}
