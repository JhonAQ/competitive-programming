#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, k; cin >> n >> k;
  vector<int> p(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    mx = max(mx, p[i]);
  }

  int lo = 1, hi = mx, ans = mx;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    __int128 total = 0;
    for (int i = 0; i < n; i++) {
      total += (p[i] + mid - 1) / mid;
      if (total > k) break;
    }
    if (total <= k) {
      ans = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }

  cout << ans << "\n";
}
