#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int n, k, ans =0;
    scanf("%d %d\n", &n, &k);
    for(int a = 1; a < n; a++){
      for(int b = a + 1; b <=n; b++){
        if((a&b) < k) ans = max(ans, a&b);
      }
    }
    cout << ans << endl;
  }
}