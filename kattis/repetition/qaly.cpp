#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc; cin >> tc;
  double res;
  while(tc--){
    double a, b; cin >> a >> b;
    res += a * b;
  }
  printf("%.3f", res);
  return 0;
}