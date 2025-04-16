#include<bits/stdc++.h>

using namespace std;


vector<vector<bool>> visited;
int m, n;

bool isVisited(int i, j){
  return visited[n*i + j];
}

vector<pair<int, int>> vecinos(pair<int, int> u){
  vector<pair<int, int>> veci;
  int i = u.first;
  int j = u.second;
  if(i-1 >=0) veci.push_back({i - 1, j});
  if(i+1 <m) veci.push_back({i + 1, j});
  if(j-1 >=0) veci.push_back({i, j - 1});
  if(j+1 <n) veci.push_back({i, j + 1});
  return veci;
}

int main(){
  int ans = 1e9;
  cin >> m >> n;
  visited.assign(m*n, false);
  string lab[m];
  queue<pair<int, int>> q;
  pair<int, int> a;
  pair<int, int> b;

  for(int i = 0; i < m; i++){
    cin >> lab[i];
    if(lab[i].find('A') != lab[i].end()) a = {i, lab[i].find('A')};
    if(lab[i].find('B') != lab[i].end()) a = {i, lab[i].find('B')};
  }

  q.push(a);
  while(!q.empty()){
    auto u = q.front(); q.pop();
    for(auto p : vecinos(u)){
      
    }
  }

}
