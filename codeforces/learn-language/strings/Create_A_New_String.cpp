#include <bits/stdc++.h>
using namespace std;

int main() {
  string m, n;
  cin >> m >> n;
  int j = 0, k= 0;
  while(m[j]) j++;
  while(n[k]) k++;

  cout << j << " " << k << endl;
  cout << m << " " << n ;

  return 0;
}