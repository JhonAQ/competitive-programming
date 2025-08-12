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


map<char, bool> dislike;

bool hasDislike(int n){
    string str = to_string(n);
    for(auto s : str){
        if(dislike[s]) return true;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k; cin >> n >> k;
    while(k--){
        char a; cin >> a;
        dislike[a] = true;
    }
    while(true){
        if(hasDislike(n)){
            n++;
            continue;
        }
        cout << n << endl;
        return 0;
    }
}

