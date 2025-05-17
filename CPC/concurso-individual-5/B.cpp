#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
int n;
vector<vector<int>> table;

bool isValid(int x){ return 0 <= x && x < n; }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  if(!(cin >> n)) return 0;
  table.assign(n, vector<int>(n, INF));

  int dx[8] = {-2,-1,1,2, 2, 1,-1,-2};
  int dy[8] = { 1, 2,2,1,-1,-2,-2,-1};

  queue<pair<int,int>> q;
  table[0][0] = 0;
  q.push({0,0});

  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int k = 0; k < 8; ++k){
      int x = i + dx[k], y = j + dy[k];
      if(isValid(x) && isValid(y) && table[x][y]==INF){
        table[x][y] = table[i][j] + 1;
        q.push({x,y});
      }
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cout << table[i][j] << (j+1==n ? '\n' : ' ');
    }
  }
}
