#include<bits/stdc++.h>

using namespace std;

int main(){
  unordered_set<int> S;
  int ans = 0;
  int n; cin >> n;
  while(n--){
    int s; cin >> s;
    S.insert(s);
  }
  int t; cin >> t;
  while(t--){
    int T; cin >> T;
    if(S.find(T) != S.end()) ans++;
  }
  cout << ans << endl;
}
