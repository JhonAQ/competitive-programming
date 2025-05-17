#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  vector<bool> s(n*2+5);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      fill(s.begin(), s.end(), false);
      for(int k = 0; k < j; k++) s[A[i][k]] = true;
      for(int k = 0; k < i; k++) s[A[k][j]] = true;
      int x = 0;
      while(s[x]) x++;
      A[i][j] = x;
    }
  }

  for(auto &fila : A){
    for(int v : fila) cout << v << ' ';
    cout << '\n';
  }
}
