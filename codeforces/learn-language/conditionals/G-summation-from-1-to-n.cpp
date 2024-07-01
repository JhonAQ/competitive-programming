#include <iostream>

using namespace std;

long long summation(long long n)
{
  return (n * (n + 1)) / 2;
}

int main()
{
  long long n;
  cin >> n;
  cout << summation(n);
  return 0;
}
