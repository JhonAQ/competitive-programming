#include <bits/stdc++.h>
#define nl "\n";

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    unsigned int n;
    cin >> n;
    unsigned int ans = n & 1;
    for (int i = 1; i < 32; i++) {
      ans = (ans << 1) | ((n >> i) & 1);
    }

    cout << ans << nl;
  }
  // TODO: Aprender a profundidad sobre tipos de datos int, long long, unsigned, etc en c++
}