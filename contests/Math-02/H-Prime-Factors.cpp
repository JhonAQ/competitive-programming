#include <bits/stdc++.h>

using namespace std;

void solve(){
  int x;
  while (cin >> x && x) {
    vector<int> fp;
    cout << x << " = ";
    if (x < 0) {
      cout << "-1 x ";
      x *= -1;
    }
    for (int i = 2; i <= sqrt(x) + 1; i++) {
      while (!(x % i)) {
        fp.push_back(i);
        x /= i;
      }
    }
    if (x != 1) fp.push_back(x);
    for (int i = 0; i < fp.size(); i++) {
      cout << fp[i];
      if (i != fp.size() - 1)
        cout << " x ";
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}