#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& LA){
  visited[u] = true;
  for(auto v : LA[u]){
    if(!visited[v])
      dfs(v, visited, LA);
  }
}

int main () {
  int tc; cin >> tc;
  cin.ignore();
  while(tc--){
    char g; cin >> g;
    int greatest = g - 'A';
    cin.ignore();

    vector<vector<int>> LA(greatest+1);
    vector<bool> visited(greatest + 1, false);

    string line;

    while(getline(cin, line) && !line.empty()){
      int a = line[0] - 'A';
      int b = line[1] - 'A';
      LA[a].push_back(b);
      LA[b].push_back(a);
    }

    int ans = 0;

    for(int i = 0; i < greatest + 1; i++){
      if(!visited[i]){
        ans++;
        dfs(i, visited, LA);
      }
    }

    cout << ans << endl;

    if(tc) cout << endl;

  }
  return 0;
}
