#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;
  string w;
  int odd_count = 0;
  for (int i = 1; i <= r; i++) {
    cin >> w;
    int len = w.length();
    int b = c - len;
    int l, rr;
    if (b % 2 == 0) {
      l = rr = b / 2;
    } else {
      odd_count++;
      int half = b / 2;
      if (odd_count % 2 == 1) {
        l = half;
        rr = b - half;
      } else {
        rr = half;
        l = b - half;
      }
    }
    cout << string(l, '.') << w << string(rr, '.') << '\n';
  }
}
