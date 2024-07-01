#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;
  string rows = "";
  for(int i = p; i > 0; --i){
    rows += "*";
    cout << rows << endl;
  }
  return 0;
}