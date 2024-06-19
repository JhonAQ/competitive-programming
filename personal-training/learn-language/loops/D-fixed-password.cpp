#include <iostream>

using namespace std;

int main()
{
  while (true)
  {
    int psw;
    cin >> psw;
    if (psw == 1999)
    {
      cout << "Correct" << endl;
      return 0;
    }
    cout << "Wrong" << endl;
  }
}