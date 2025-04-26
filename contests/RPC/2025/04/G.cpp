#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> adj(n + 1);
  adj.reserve(n + 1);
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    /*cout << x << y;*/
    adj[x].push_back(y);
  }
  for (int u = 1; u <= n; u++) sort(adj[u].begin(), adj[u].end());
  vector<vector<int>> G(n + 1);
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      if (v > u) {
        if (binary_search(adj[v].begin(), adj[v].end(), u)) {
          G[u].push_back(v);
          G[v].push_back(u);
        }
      }
    }
  }
  vector<char> vis(n + 1, 0);
  int ans = 0;
  vector<int> stk;
  stk.reserve(n);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      stk.clear();
      vis[i] = 1;
      stk.push_back(i);
      int es = 0;
      for (size_t idx = 0; idx < stk.size(); idx++) {
        int u = stk[idx];
        es += (int)G[u].size();
        for (int v : G[u]) {
          if (!vis[v]) {
            vis[v] = 1;
            /*cout << "veertice:" << endl;*/
            /*cout << v << endl;*/
            stk.push_back(v);
          }
        }
      }
      int s = stk.size(), e = es / 2;
      if (e == s * (s - 1) / 2) {
        if (s == k) ans++;
      }
    }
  }
  cout << ans << endl;
}
