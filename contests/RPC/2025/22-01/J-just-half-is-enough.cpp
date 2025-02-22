#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
      int n, m; cin >> n >> m;
      
      vector<pair<int, int>> edges(m);
      int count = 0;
      
      for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        if (edges[i].first < edges[i].second) ++count;
      }
      if (count >= (m + 1) / 2) {
        for (int i = 1; i <= n; ++i) cout << i << " ";
      } else {
        for (int i = n; i >= 1; --i) cout << i << " ";
      }
      cout << '\n';
    }
}
