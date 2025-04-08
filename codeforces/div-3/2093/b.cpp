#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--){
    string s; cin >> s;
    int n = s.size();
    int best = 0;
    for (int i = 0; i < n; i++) {
      if(s[i] != '0'){
        int ceros = 0;
        for (int j = 0; j < i; j++){
          if(s[j] == '0') ceros++;
        }
        best = max(best, ceros + 1);
      }
    }
    cout << (n - best) << "\n";
  }
  return 0;
}
