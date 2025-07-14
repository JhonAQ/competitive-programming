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
vector<vi> maze;
int n, m, k;
//TODO Averiguar como es con const
bool possible(int i, int j){
  bool ci = 0 <= i && i < n;
  bool cj = 0 <= j && j < m;
  return ci && cj && maze[i][j] == '.';
}

vector<ii> getChild(ii v){
  vector<ii> res;
  int i = v.first;
  int j = v.second;
  if(possible(i - 1, j)) res.push_back({i - 1, j});
  if(possible(i, j + 1)) res.push_back({i, j + 1});
  if(possible(i + 1, j)) res.push_back({i + 1, j});
  if(possible(i, j - 1)) res.push_back({i, j - 1});
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m >> k;
  maze.assign(n, vector<int>(m));
  int l = 0;
  ii first;
  FOR(i, 0, n){
    FOR(j, 0, m){
      cin>>maze[i][j];
      if(!first && maze[i][j] == '.'){
        first = {i, j}; 
      }
    }
  }
  queue<ii> q; q.push(first);
  set<int, vector<ii>> levels;
  const vector<vi> visited(n, vi(m, 0));
  while(!q.empty()){
    ii actual = q.front(); q.pop();
    visited[actual.first][actual.second] = 1;
    levels[l].push_back(actual);
    for(auto a : getChild(actual)){
      if(!visited[a.first][a.second])
        q.push(a);
    }
    l++;
  }
  for(int i = l; i >=0 && k; i--){
    for(auto x : levels[ i]{
      maze[x.first][x.second] = 'X';
      k--;
    }
  }
  FOR(i, 0, n){
    FOR(j, 0, m){
      cout << n << ((i != n - 1) ? ' ' : '\n');
    }
  }
}
