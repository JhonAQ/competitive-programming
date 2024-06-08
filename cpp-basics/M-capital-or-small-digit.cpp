#include <iostream>

using namespace std;

int main()
{
  char x;
  cin >> x;

  if ('0' <= x and x <= '9')
  {
    cout << "IS DIGIT";
    return 0;
  }

  cout << "ALPHA" << endl;

  if ('A' <= x and x <= 'Z')
  {
    cout << "IS CAPITAL";
  }

  if ('a' <= x and x <= 'z')
  {
    cout << "IS SMALL";
  }
}