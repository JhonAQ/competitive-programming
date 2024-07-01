#include <bits/stdc++.h>
using namespace std;

int main() {
  char a[100], b[100], c[100], d[100];
  scanf("%s%s", a, b);
  scanf("%s%s", c, d);
  if(strcmp(b, d) == 0) cout << "ARE Brothers";
  else cout << "NOT";
  return 0;
}