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
#define ROF(i, a, b) for (auto i = a; i > (b); --i)
#define sz(x) (int)(x).size()
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n; cin >> n;
  vi nums(n);
  ll a = n;
  while(a--) {cin>> nums[a];}
  ll ans = nums[0];
  ll lim = nums[0];
  for(ll i = 1; i < n; i++){
    if(lim == 0)break;
    if(nums[i] < lim){
      ans+=nums[i];
      lim = nums[i];
    }else{
      ans += lim - 1;
      lim--;
    }
  }
  cout << ans << endl;
}
