#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int n, k; cin >> n >> k;
    bool sorted = true;
    int actual; cin >> actual; n--;
    while(n--){
      int nuevo; cin >> nuevo;
      if(nuevo < actual){
        sorted = false;
      }
      actual = nuevo;
    }
    if(k == 1 && !sorted){
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    // if(sorted || k > 1){
    //   cout << "YES\n";
    //   continue;
    // }
    // cout << "NO\n";
  }
}
