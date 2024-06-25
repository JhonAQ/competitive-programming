#include <bits/stdc++.h>
using namespace std;

int main() {
  double n; cin >> n;
  double res = n * 5280 / 4854 * 1000;
  int r = (int) ((double) res + 0.5);
  cout << r;
  return 0;
}