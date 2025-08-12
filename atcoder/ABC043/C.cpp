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
    int n; cin >> n;
    int arr[n];
    for(auto& a : arr) cin >> a;
    ll ans = INF;
    for( int t = -100; t <= 100 ; t++){
        ll cost = 0;
        for(auto n : arr){
            cost += ( n - t) * ( n - t);
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;

}

