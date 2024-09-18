#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

bitset<501> isP;

ull jpow(ull n, ull k) {
  if (k == 0) return 1;
  if (k & 1)
    return n * jpow(n * n, k >> 1);
  return jpow(n * n, k >> 1);
}

void generatePrimes() {
  isP.set();
  isP[1] = isP[0] = 0;
  for (int i = 2; i <= 500; i++)
    if (isP[i])
      for (int j = i * i; j < 501; j += i)
        isP[j] = 0;
}

int main() {
  set<ull> n;
  generatePrimes();
  n.insert(1);
  for (int i = 2; i < 65536; i++)
    for (int j = 2; j < 500; j++)
      if (!isP[j] && j * log2(i) < 64)
        n.insert(jpow(i, j));

  for (set<ull>::iterator it = n.begin(); it != n.end(); it++)
    cout << *it << "\n";
}