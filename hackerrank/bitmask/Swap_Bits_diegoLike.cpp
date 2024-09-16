#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    // cout << n << endl;
    int ans = 0;
    for (int i = 0; i <= 32; i += 2) {
      int impar = (n >> i) & 1;
      int par = (n >> i + 1) & 1;
      int conjunto = (par << 1) | impar;
      if (impar ^ par) conjunto = (impar << 1) | par;

      if (i == 0) {
        ans |= conjunto;
      } else {
        conjunto <<= 2;
        ans |= conjunto;
      }
      // cout << "Impar: " << impar<<endl;
      // cout << "Par: " << par << endl;
    }
    cout << ans << " ";
  }
}