#include <bits/stdc++.h>
using namespace std;

string makeRow(int x) {
  string rpta = "";
  for (int i = 0; i < x; ++i) {
    rpta += "*";
  }
  return rpta;
}

int main() {
  int x;
  cin >> x;
  for (int i = x; i > 0; --i) {
    cout << makeRow(i) << endl;
  }
  return 0;
}