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
  int tc; cin >> tc;
  while(tc--){
    int n, m, a, b; cin >> n >> m >> a >> b;
    int ans = 1;
    if(abs(n - a) > abs(m - b)){
      n = n - a + 1;
    }else{
      m = m - b + 1;
    }
    ans += ceil(log2(m));
    ans += ceil(log2(n));
    cout << ans << endl;
  }
}
