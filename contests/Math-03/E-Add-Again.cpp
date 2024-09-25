#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  while (cin >> k && k) {
    int ans;
    int s = 0;
    int e = k;
    while (k--) {
      int a;
      cin >> a;
      s += a;
    }
    ans = (e - 1) * s * ((pow(10, e) - 1) / 9);
    // cout << "s: " << s << endl;
    cout << ans <<endl;
  }
}