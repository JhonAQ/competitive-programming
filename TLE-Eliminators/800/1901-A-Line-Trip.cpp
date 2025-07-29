#include<bits/stdc++.h>

using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    int n, x; cin >> n >> x;
    int prev; cin >> prev;
    int ans = prev;
    n--;
    while(n--){
      int act; cin >> act;
      ans = max(ans, act - prev);
      prev = act;
    }
    ans = max(ans, 2 * (x - prev));
    cout << ans << endl;
  }
}
