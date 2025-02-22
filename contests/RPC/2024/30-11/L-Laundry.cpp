#include<bits/stdc++.h>
#define int long long

using namespace std;

int cargas(int n, double k){
  return ceil(n / k);
}

int resto(int n, int k){
  return n - n % k;
}

void mandar(int n, int& x, int& y, int k){
  if(resto(x, k) < resto(y, k)){
    y += n;
    return;
  }
  x += n;
}

signed main(){
  int tc; cin >> tc;

  while(tc--){
    int k; cin >> k;
    int a, b, c;
    cin >> a >> b >> c;
    int ab; cin >> ab;
    mandar(ab, a, b, k);
    int bc; cin >> bc;
    mandar(bc, b, c, k);
    int ac; cin >> ac;
    mandar(ac, a, c, k);
    int abc; cin >> abc;
    if(resto(a, k) > resto(b, k) && resto(a, k) > resto(c, k)){
      a += abc;
    }
  }
}
