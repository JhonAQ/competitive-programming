#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ======================== " << endl;
#define rep(i, a, b) for(auto i = a; i < (b) ; ++i)
#define sz(x) (int)(x).size()

const ll INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int K; cin >> K;
  vi col(K);
  int ts = 0;
  for (int i = 0; i < K; i++) {
    cin >> col[i];
    ts += col[i];
  }

  vector<vector<ll>> dp(ts + 1, vector<ll>(ts + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= ts; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
    }
  }

  ll ans = 1;
  int tt = 0;
  for (int i = 0; i < K; i++) {
    ans = (ans * dp[tt + col[i] - 1][col[i] - 1]) % MOD;
    tt += col[i];
  }

  cout << ans << endl;
}
