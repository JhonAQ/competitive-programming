#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n; cin >>n;
  vector<ll> dp(n + 1 + 6, 0);
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 1;
  dp[5] = 1;
  dp[6] = 1;
  for(ll i = 1; i < n; i++){
    for(int j = 1; j <= 6; j++){
      // raya;
      dp[i + j] += dp[i] % (1000000000 + 7);
      // dbg(i);
      // dbg(j);
      // dbg(dp[i + j]);
      // dbg(dp[i]);
    }
  }
  cout << dp[n] % MOD << endl;
}
