#include <iostream>

using namespace std;

void sort(double max, double mid, double min)
{
  if (mid > max)
    swap(mid, max);
  if (min > max)
    swap(min, max);
  if (mid < min)
    swap(mid, min);
  cout << min << endl;
  cout << mid << endl;
  cout << max << endl;
  cout << endl;
}

void swap(double &a, double &b)
{
  double temp = a;
  a = b;
  b = temp;
}

int main()
{
  double a, b, c;
  cin >> a >> b >> c;
  sort(a, b, c);
  cout << a << endl;
  cout << b << endl;
  cout << c;
}