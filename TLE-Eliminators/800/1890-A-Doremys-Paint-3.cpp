#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc;
    while(tc--){
      int n; cin >> n;
      map<int, int> f;
      while(n--){
        int a; cin >> a;
        f[a]++;
      }
      if(f.size() > 2){
        cout << "NO" << '\n';
        continue;
      }
      if(f.size() == 1 ){
        cout << "YES" << '\n';
        continue;
      }
      int a = f.begin()->second;
      int b = f.rbegin()->second;

      if(abs(a - b) <= 1){
        cout << "YES" << '\n';
        continue;
      }
      cout << "NO" << '\n';
    }
}
