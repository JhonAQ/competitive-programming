#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    if (!(i & 1))
    {
      cout << i;
      if (i == n or i == n - 1)
        continue;
      cout << "\n";
    }
  }
  if(n == 1) cout << -1;

}