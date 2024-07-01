#include <iostream>

using namespace std;

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    long long k;
    cin >> k;
    long long result = 1;
    for(int i = 2; i <= k; i++){
      result *= i;
    }
    cout << result << endl;
  }
}
