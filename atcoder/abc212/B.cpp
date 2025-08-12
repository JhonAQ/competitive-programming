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

bool equalDigits(string str){
    auto f = str[0];
    for(auto l : str){
        if(l != f){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    string str; cin >> str;
    if(equalDigits(str)){
        cout << "Weak" << endl;
        return 0;
    }
    auto f = str[0];
    int seq[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 0; i < 3; i++){
        if(str[i] + 1 != str[i + 1] && !(str[i] == '9' && str[i + 1 ] == '0')){
            cout << "Strong" << endl;
            return 0;
        }

    }
    cout << "Weak" << endl;
}

