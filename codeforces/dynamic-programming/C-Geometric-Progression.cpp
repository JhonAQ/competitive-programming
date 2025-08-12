
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

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n; ll k;
  cin >> n >> k;

  vector<ll> a(n);
  for(auto &x : a) cin >> x;

  unordered_map<ll, ll> r, l;
  r.reserve(n * 2);
  l.reserve(n * 2);

  for(ll x : a) ++r[x];

  ll ans = 0;
  for(ll x : a){
    --r[x];
    if(k == 1){
      ans += l[x] * r[x];
    }else{
      if(x % k == 0){
        ll prev = x / k;
        ll nxt = x * k;
        ans += l[prev] * r[nxt];
      }
    }
    ++l[x];
  }

  cout << ans << endl;
}
