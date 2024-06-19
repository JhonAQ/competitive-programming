#include <iostream>

using namespace std;

char invert(char a)
{
  if ('a' <= a and a <= 'z')
    return a - 32;
  return a + 32;
}

int main()
{
  char x;
  cin >> x;
  cout << invert(x);
}