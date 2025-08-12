
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> blocked(N + 1);
    for (int i = 0; i < M; ++i) {
      int u, v; cin >> u >> v;
      blocked[u].push_back(v);
      blocked[v].push_back(u);
    }

    vector<ll> prev(N + 1, 0), cur(N + 1, 0);
    prev[1] = 1;

    for (int day = 1; day <= K; ++day) {
      ll total = 0;
      for (int v = 1; v <= N; ++v) {
        total += prev[v];
        if (total >= MOD) total -= MOD;
      }

      for (int v = 1; v <= N; ++v) {
        ll res = total;
        res -= prev[v];
        if (res < 0) res += MOD;

        for (int u : blocked[v]) {
          res -= prev[u];
          if (res < 0) res += MOD;
        }

        cur[v] = res % MOD;
      }

      prev.swap(cur);
      fill(cur.begin(), cur.end(), 0);
    }

    cout << (prev[1] % MOD + MOD) % MOD << "\n";
}
