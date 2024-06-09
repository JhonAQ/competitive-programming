#include <iostream>

using namespace std;

int main()
{
  string s;
  cin >> s;
  if (s.find('.') != -1 and s.substr(s.find('.') + 1) != "000")
  {
    float n = stof(s);
    int entero = n + 0;
    string decimal = "0." + s.substr(s.find('.') + 1);
    cout << "float " << entero << " " << decimal;
  }
  else
  {
    cout << "int " << stof(s);
  }
}