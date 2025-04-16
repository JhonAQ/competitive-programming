#include <bits/stdc++.h>

using namespace std;

int main() {
  int s; cin >> s;
  
  vector<int> ns(s);
  for (int i = 0; i < s; ++i) 
    cin >> ns[i];

  int tc; cin >> tc;
  while (tc--) {
    int l, r, ans = 0; cin >> l >> r;
    if (l > r) swap(l, r);
    for (int i = l; i <= r; ++i)
      ans += ns[i];
    cout << ans << endl;
  }
}
