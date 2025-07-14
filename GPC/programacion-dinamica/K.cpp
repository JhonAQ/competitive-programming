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
  long double  a; long double r;
  long double pi = 3.141592653589793;
  cin >> a >> r;
  long double part1 = r * sin(pi/a);
  long double part2  = (1.0 - (double) sin(pi/a));
  long double res = part1 / part2;
  cout<<fixed<<setprecision(8)<<res<<endl;
  // cout << res;
  // printf("%.8llf\n", res);
}
