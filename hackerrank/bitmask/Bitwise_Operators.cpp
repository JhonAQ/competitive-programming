#include <bits/stdc++.h>

using namespace std;

void calculateTheMaximum(int n, int k) {
  int maxAnd = 0;
  int maxOr = 0;
  int maxXor = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j > i && j <= n; j++) {
      int AND = i & j;
      int OR = i | j;
      int XOR = i ^ j;
      // cout << "i:\t" << i << endl;
      // cout << "j:\t" << j << endl;
      // cout << AND << " " << OR << " " << XOR << endl;
      if(AND<k) maxAnd = max(maxAnd, AND);
      if(OR<k) maxOr = max(maxOr, OR);
      if(XOR<k) maxXor = max(maxXor, XOR);
      // cout << maxAnd << " " << maxOr << " " << maxXor << endl << endl;
    }
  }
  cout << maxAnd << endl;
  cout << maxOr << endl;
  cout << maxXor;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  calculateTheMaximum(n, k);
}