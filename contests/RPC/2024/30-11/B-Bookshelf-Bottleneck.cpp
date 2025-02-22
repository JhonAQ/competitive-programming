#include<bits/stdc++.h>

#define int long long

using namespace std;



bool impossible = false;

int chooseBest(vector<int> n, int H){
  sort(n.begin(), n.end());
  int a = n[0], b = n[1], c = n[2];
  if(a > H && b > H && c > H) impossible = true;
  if(b <= H || c <= H){
    return a;
  }
  if(a <= H || c<=H){
    return b;
  }
  return c;
}

signed main(){
  int n, H; cin >> n >> H;
  int ans = 0;
  while(n--){
    int a, b, c; cin >> a >> b >> c;
    ans += chooseBest({a, b, c}, H);
    if(impossible){
      cout << "impossible" << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
