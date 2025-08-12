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
    string str; cin >> str;
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '0'){
            ans += '0';
        }else if(str[i] == '1'){
            ans += '1';
        }else{
            if(ans.size() == 0) continue;
            ans = ans.substr(0, ans.size() - 1);
        }

    }
    cout << ans << endl;
}

