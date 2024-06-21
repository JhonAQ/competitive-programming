#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long x;
    cin >> x;
    long long result = x * (x + 1) / 2;
    for (int i = 0; pow(2, i) <= x; i++) {
      result -= 1 << (i + 1);
    }
    cout << result << endl;
  }
  return 0;
}