#include <bits/stdc++.h>

using namespace std;

const int n = 100000;

vector<int> primes;
unordered_set<int> primeSet;
vector<int> lp(n + 1);

void generatePrimes() {
  for (int i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
      primeSet.insert(i);
    }
    for (int j = 0; i * primes[j] <= n; ++j) {
      lp[i * primes[j]] = primes[j];
      if (primes[j] == lp[i]) break;
    }
  }
}

int countConsecutiveSum(const vector<int>& arr, int x) {
  int count = 0;
  // if (x == 1009) cout << "size: " << (int)arr.size();
  for (int i = 0; i < arr.size(); i++) {
    int sum = 0;

    // if (x == 1009) cout << i << endl;
    // if (i == 169) cout << 'hoaaaaa';

    for (int j = i; sum < x && j < arr.size(); j++) {

      sum += arr[j];

      // if (j == 167) {
      //   cout << "step (j): " << j << "\nsum: " << sum << endl;
      // }
    }
    if (sum == x) {
      count++;
    }
  }
  return count;
}

int main() {
  generatePrimes();
  int n;
  while (cin >> n && n) {
    cout << countConsecutiveSum(primes, n) << endl;
    // countConsecutiveSum(pr, n);
  }

  return 0;
}
