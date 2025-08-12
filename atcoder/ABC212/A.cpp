#include<bits/stdc++.h>
using ll = long long;
#define endl '\n'
#define sz(x) (int)(x).size()

const ll INF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

int main(){
    int a, b; cin >> a >> b;

    if(b == 0){
        cout << "Gold" << endl;
    }else if(a == 0){
        cout << "Silver" << endl;
    }else
        cout << "Alloy" << endl;
}

