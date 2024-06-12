#include <iostream>

using namespace std;

int evaluate(int a, int b, char s, int c)
{
  switch (s)
  {
  case '+':
    if (a + b != c)
    {
      cout << a + b;
      return 0;
    }
    break;
  case '-':
    if (a - b != c)
    {
      cout << a - b;
      return 0;
    }
    break;
  case '*':
    if (a * b != c)
    {
      cout << a * b;
      return 0;
    }
    break;
  }
  cout << "Yes";
  return 0;
}

int main()
{
  int a, b, c;
  char s, q;

  cin >> a >> s >> b >> q >> c;
  evaluate(a, b, s, c);
}