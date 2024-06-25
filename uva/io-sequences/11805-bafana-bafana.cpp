#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc, i = 0; cin >> tc;
  while(i++, i <= tc){
    int n, k, p; cin >> n >> k >> p;
    int res = ((k + p) % n) != 0 ? ((k + p) % n) : n;
    cout << "Case " << i << ": " << res << endl;
  }
}