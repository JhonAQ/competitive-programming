#include <bits/stdc++.h>

using namespace std;

bitset<1000010> isP;
vector<int> pr;

void sieve() {
  isP.set();
  isP[0] = isP[1] = 0;
  for (int i = 2; i * i < 1000000; i++) {
    if (isP[i]) {
      pr.push_back(i);
      for (int j = i * i; j < 1000000; j += i) {
        isP[j] = 0;
      }
    }
  }
}

int countConsecutiveSum(const vector<int>& arr, int x) {
  int count = 0;
  int start = 0;
  int sum = 0;

  for (int end = 0; end < arr.size(); ++end) {
    sum += arr[end];

    while (sum > x && start <= end) {
      sum -= arr[start];
      start++;
    }

      if(x == 1009){
        cout << "por fin apareces malnacido \t" << sum << endl; 
      }
    if (sum == x) {
      count++;
    }
  }

  return count;
}

int main() {
  sieve();
  int n;
  while (cin >> n && n) {
    cout << countConsecutiveSum(pr, n) << endl;
  }

  return 0;
}
