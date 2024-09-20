#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

const int mx = 32001;

bitset<mx> bt;
int e = -1;

vector<int> primes[200];
int prime[mx];

void find(int a, int b) {
  int p = -1;
  int i = 0;
  while (i <= e && prime[i] <= b) {
    if (a > prime[i]) {
      i++;
      continue;
    }
    if ((prime[i + 1] - prime[i] == prime[i + 2] - prime[i + 1]) && prime[i + 1] <= b &&
        prime[i + 2] <= b) {
      int t = prime[i + 1] - prime[i];
      p++;
      primes[p].push_back(prime[i]);
      primes[p].push_back(prime[i + 1]);
      primes[p].push_back(prime[i + 2]);
      i += 2;
      while (prime[i + 1] - prime[i] == t) {
        primes[p].push_back(prime[i + 1]);
        i++;
      }
    } else i++;
  }
}

void sieve() {
  bt[0] = bt[1] = 1;
  prime[++e] = 2;
  for (int i = 4; i < mx; i += 2)
    bt[i] = 1;
  for (int i = 3; i * i <= mx; i += 2) {
    if (!bt[i]) {
      prime[++e] = i;
      for (int j = i * i; j < mx; j += i){
        bt[j] = 1;
      }
    }
  }
  for (int i = 179; i < mx; i += 2) {
    if (!bt[i]){
      prime[++e] = i;
    }
  }
}

int main() {
  sieve();
  find(0, 32000);
  int a, b, c, d;
  while (scanf("%d %d", &c, &d)) {
    if (!c && !d) break;
    b = max(c, d);
    a = min(c, d);
    for (int i = 0; i < 162; i++) {
      int t = primes[i][0];
      int x = primes[i].size() - 1;
      int tt = primes[i][x];
      if (t >= a && tt <= b) {
        cout << primes[i][0] << "";
        for (int j = 1; j <= x; j++)
          cout << " " << primes[i][j];
        cout << ln;
      }
    }
  }
  return 0;
}