#include <bits/stdc++.h>
using namespace std;

string toBinary(int x) {
  string bin = "";
  while (x > 0) {
    bin = (x % 2 == 1 ? "1" : "0") + bin;
    x /= 2;
  }
  return (bin);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    string n = toBinary(x);
    int count = 0;
    for (int i = 0; i < n.size(); i++) {
      if (n[i] == '1') count++;
    }
    cout << (1 << count) - 1 << endl;
  }
  return 0;
}