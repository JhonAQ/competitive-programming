#include <bits/stdc++.h>
using namespace std;

int main() {
  int  tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int res = (n * 567 / 9 + 7492) * 235 / 47 - 498;
    res /= 10;
    res %= 10;
    cout << abs(res) << endl;
  }
  return 0;
}