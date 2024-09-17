#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ln "\n"
const int n = 1000000;

vector<bool> isPrime(n + 1, true);
vector<int> primes;

void generatePrimes() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      if ((ll)i * i <= n) {
        for (int j = i * i; j <= n; j += i) isPrime[j] = false;
      }
    }
  }
}

void solve(int k) {
  int left = 0;
  int right = primes.size() - 1;

  while (left <= right) {
    int sum = primes[left] + primes[right];

    if (sum == k) {
      cout << (primes[left] + primes[right]) << " = " << primes[left] << " + " << primes[right] << ln;
      return;
    }

    if (sum < k)
      ++left;
    else
      --right;
  }

  cout << "Esto nunca se va a ejecutar xd" << ln;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  generatePrimes();
  int c;
  while (cin >> c && c != 0) solve(c);

  return 0;
}
