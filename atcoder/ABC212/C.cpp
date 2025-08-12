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
    int n, m; cin >> n >> m;
    vi arrN(n);
    for(auto& a : arrN) cin >> a;
    sort(arrN.begin(), arrN.end());
    ll ans = INF;
    while(m--){
        int a; cin >> a;
        auto it = lower_bound(arrN.begin(), arrN.end(), a);
        if(it == arrN.begin()){
            ans = min(ans, (ll)abs(a - *it));
            continue;
        }
        if(it == arrN.end()){
            ans = min(ans, (ll)abs(a - arrN.back()));
            continue;
        }
        ans = min(ans, (ll)abs(a - *it));
        ans = min(ans, (ll)abs(a - *(it -1)));
    }
    cout << ans << endl;
}

