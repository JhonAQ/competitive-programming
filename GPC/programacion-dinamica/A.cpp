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
  ll n, q; cin >> n >> q;
  vi nums(n);
  FOR(i, 0, n) cin>>nums[i];
  vl dp(n + 1); 
  dp[0] = nums[0];
  FOR(i, 1, nums.size()){
    dp[i] = dp[i-1] + nums[i];
  }
  while(q--){
    ll l, r; cin >> l >> r;
    if(l == 0){
      cout << dp[r - 1] << endl;
      continue;
    }
    cout << dp[r - 1] - dp[l - 1] << endl;
  }
}
