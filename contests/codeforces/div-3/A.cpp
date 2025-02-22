#include<bits/stdc++.h>
#define RAYA cerr << "-----------------------------------" << endl
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

int main(){
  //RAYA;
  int tc; cin >> tc;
  //DBG(tc);
  while(tc--){
    //RAYA;
    int n, k; cin >> n >> k;
    //DBG(n);
    //DBG(k);
    int ans = 0;
    bool flag = true;
    while(n--){
      string s; cin >> s;
      //DBG(s);
      if(s.size() <= k && flag){
        ans++;
        k -= s.size();
      }else{
        flag = false;
      }
    }
    cout << ans << endl;
  }
}
