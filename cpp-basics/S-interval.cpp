#include <iostream>

using namespace std;

string interval(double n)
{
  if (n > 100 or n < 0)
    return "Out of Intervals";
  cout << "Interval ";
  if (n > 75)
    return "(75,100]";
  if (n > 50)
    return "(50,75]";
  if (n > 25)
    return "(25,50]";
  return "[0,25]";
}

int main()
{
  double n;
  cin >> n;
  cout << interval(n);
}