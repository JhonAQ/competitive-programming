#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int G, R;
  if (!(cin >> G >> R)) return 0;

  int mix_gr = min(G, R);
  G -= mix_gr;
  R -= mix_gr;

  int mix_3g = G / 3; G %= 3;

  int mix_2g = G / 2; G %= 2;

  int mix_1g = G;

  int result = 0;
  result += 10LL * mix_gr;
  result += 10LL * mix_3g;
  result += 3LL  * mix_2g;
  result += 1LL  * mix_1g;

  cout << result << endl;
}
