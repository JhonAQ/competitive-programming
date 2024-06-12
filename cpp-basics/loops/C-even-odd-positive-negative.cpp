#include <iostream>

using namespace std;

int main()
{
  int even = 0, odd = 0, positive = 0, negative = 0;
  int tc;

  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    (n & 1) ? odd++ : even++;
    (n > 0) ? positive++ : negative++;
    if(n == 0) negative--;
  }
  cout << "Even: " << even << endl;
  cout << "Odd: " << odd << endl;
  cout << "Positive: " << positive << endl;
  cout << "Negative: " << negative << endl;
}