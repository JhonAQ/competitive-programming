#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int tc, n, st, rpta;
  cin >> tc;
  for(int i = 1; i <= tc; i++){
    cin >> n;
    n--;
    cin >> rpta;
    while(n--){
      cin >> st;
      rpta = max(st, rpta);
    }
    cout << "Case " << i << ": " << rpta << '\n';
  }
}
