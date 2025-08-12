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
const int MOD = 998244353;
vector<vi> dp;
vector<vi> antiAdj;
int n, m, k;

ll solve(int i, int k){
    if(k < 0) return 0;
    if(k == 0) return (i == 1 ? 1 : 0);
    if(dp[i][k] != -1) return dp[i][k];
    ll total = 0;
    for(int j = 1; j <= n; j++){
        if(j == i) continue;
        if(find(antiAdj[i].begin(), antiAdj[i].end(), j ) != antiAdj[i].end()){
            continue;
        }
        total = (total + solve(j, k -1)) %MOD;
        // total += solve(j , k - 1) %MOD;
    }
    dp[i][k] = total % MOD;
    return dp[i][k] % MOD;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m >> k;
    dp.assign(n + 1, vi(k + 1, -1));
    antiAdj.assign(n + 1, vi());
    while(m--){
      int u; cin >> u;
      int v; cin >> v;
      antiAdj[u].push_back(v);
      antiAdj[v].push_back(u);
    }
    cout << solve(1, k) << endl;
}
