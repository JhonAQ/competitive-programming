#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ln "\n"
const int n = 1000000;

vector<int> primes;
vector<int> lp(n + 1);

void generatePrimes() {
  for (int i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; i * primes[j] <= n; ++j) {
      lp[i * primes[j]] = primes[j];
      if (primes[j] == lp[i]) break;
    }
  }
}

void solve(int k) {
  int left = 0;
  int right = primes.size() - 1;

  while (left <= right) {
    int sum = primes[left] + primes[right];

    if (sum == k) {
      cout << k << " = " << primes[left] << " + " << primes[right] << ln;
      return;
    }

    if (sum < k)
      ++left;
    else
      --right;
  }

  cout << "No se va a ejecutar esto xd" << ln;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  generatePrimes();
  int c;
  while (cin >> c && c != 0) solve(c);
  return 0;
}
