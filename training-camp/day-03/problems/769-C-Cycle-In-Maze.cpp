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
  int n, m, k; cin >> n >> m >> k;
  if(k&1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  vector<vector<char>> table(n, vector<char>(m));
  ii in;
  FOR(i, 0, n){
    FOR(j, 0, m){
      cin>>table[i][j];
      if(table[i][j] == 'X'){
        in = {i, j};
      }
    }
  }
  int i = k/2;
  string ans = "";

  auto possible = [table, n, m] (int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m && table[i][j] != '*';
  };

  for(int i = 0; i < k/2; i++){
    if(possible(in.first + 1, in.second)){
      ans = ans + "D";
      in = {in.first + 1, in.second};
    }else if(possible(in.first, in.second - 1)){
      ans = ans + "L";
      in = {in.first, in.second - 1};
    }else if(possible(in.first, in.second + 1)){
      ans = ans + "R";
      in = {in.first, in.second + 1};
    }else if(possible(in.first - 1, in.second)){
      ans = ans + "U";
      in = {in.first - 1, in.second};
    }else{
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  map<char, char> invert;
  invert.insert( {'D', 'U' });
  invert.insert( {'L', 'R' });
  invert.insert( {'R', 'L' });
  invert.insert({ 'U', 'D' });
  string second = "";
  for(int i = 0; i < ans.size(); i++){
    second = invert.at(ans[i]) + second;
  }
  ans += second;
  cout << ans << endl;
}



