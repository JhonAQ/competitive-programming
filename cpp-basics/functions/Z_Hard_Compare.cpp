#include <bits/stdc++.h>
using namespace std;

int main() {
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (b * log(a) > d * log(c) ? "YES" : "NO");
  return 0;
}