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
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  //bcdefghijklmnopqrsatuvwxyz
  vector<vi> g(26, vi()) ;
  vector<string> s(2);
  int n; cin >> n;
  cin >> s[0];
  bool can = 1;
  //for (auto i = 1; i < n; ++i) {
  //  bool dif = 0;
  //  for (auto j = 0u; j < min(s[i].size(), s[i-1].size()); ++j) {
  //    if (s[])
  //  }
  //}
  for (auto i = 1; i < n; ++i) {
    int i2 = (1&i);
    int i1 = (i2)?0:1;
    cin >> s[i2];
    bool dif = 0;
    for (auto j = 0u; j < min(s[0].size(), s[1].size()); ++j) {
      if (s[i1][j] != s[i2][j]) {
        dif =1;
        g[ s[i1][j]-'a' ].push_back( (s[i2][j]-'a'));
        //cout << s[i1][j] << ' ' << s[i2][j] <<'\n';
        break;
      }
    }
    if (not dif) {
      if (s[i1].size() > s[i2].size() ) { can = 0; break; }
    }
  }
  if (not can) 
  {
    cout << "Impossible\n";
    return 0;
  }
  vi rep(26), org;
  for(auto& li: g) {
    for(auto& v: li) {
      rep[v]++;
    }
  }
  for (auto v = 0; v < 26; ++v) {
    if (rep[v] == 0) org.push_back(v);
  }
  for(auto j = 0u; j < org.size(); ++j) 
  {
    int v = org[j];
    for(auto& u: g[v]) 
      if (--rep[u] == 0) org.push_back(u);
  }
  if(org.size() != 26u) {
    //cerr << org.size() <<'\n';
    cout << "Impossible\n";
    return 0;
  } else {
    for(auto& c: org) cout << (char)(c+'a');
    cout << '\n';
  }
  
}
