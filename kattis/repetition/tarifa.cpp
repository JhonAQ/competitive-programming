#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n; cin >> x >> n;
  int res = x * n + x;
  while(n--){
    int a; cin >> a;
    res -= a;
  }
  cout << res;
  return 0;
}