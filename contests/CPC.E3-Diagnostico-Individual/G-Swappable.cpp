#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);

  map<int, int> freq;

  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    freq[nums[i]]++;
  }

  long long totalPairs = (long long)n * (n - 1) / 2;

  for (auto &entry : freq) {
    int count = entry.second;
    if (count > 1) {
      totalPairs -= (long long)count * (count - 1) / 2;
    }
  }

  cout << totalPairs << endl;

  return 0;
}
