#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n == 0) cout << "01";
  if(n == 1) cout << "05";
  if(n >= 2) cout << "25";
  return 0;
}