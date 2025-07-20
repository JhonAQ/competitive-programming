#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = int;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
const ll INF = 1e18;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc; cin >> tc;
  for(int r = 1; r <= tc;r++){
    int n; cin >> n;
    vector<int> nums(n -1);
    vector<int> dp(n - 1);
    dp[0] = nums[i];
    int max;
    int sM;
    int eM;
    ii index = { -1, -1};
    for(int i = 1; i < n - 1; i++){
      cin >> nums[i];
      if(dp[i - 1] + nums[i] > )
    }
  }
}
