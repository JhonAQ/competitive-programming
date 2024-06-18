#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  while (true) {
    cin >> N >> M;
    if(N <= 0 || M <= 0) break;
    int sum = 0;
    if (N > M) {
      N = N ^ M;
      M = N ^ M;
      N = N ^ M;
    }
    for (int i = N; i <= M; ++i) {
      sum += i;
      cout << i << " ";
    }
    cout << "sum =" << sum << endl;
  }
  return 0;
}