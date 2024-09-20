#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc, lg = 0, ln = lg;
  cin >> tc;
  while(tc--){
    int n; cin >> n;
    if(n > lg){
      ln = lg;
      lg = n;
    } else if (n > ln && n!=lg){
      ln = n;
    }
  }
  cout << ln;
}