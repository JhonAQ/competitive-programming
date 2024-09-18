#include <bits/stdc++.h>

using namespace std;

long long n = 10000000;
vector<int> p;
unordered_set<int> ps;
vector<int> lp(n + 1);

void generatePrimes() {
  for (int i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      p.push_back(i);
      ps.insert(i);
    }
    for (int j = 0; i * p[j] <= n; ++j) {
      lp[i * p[j]] = p[j];
      if (p[j] == lp[i]) break;
    }
  }
}

void solve(int x) {
  if(x <= 3){
    cout << 0 << endl;
    return;
  }
  int left = 0;
  int right = p.size() - 1;
  while (left + 1 != right) {
    int midd = ((right - left) / 2) + left;
    // cout << p[left] << " " << p[midd] << " " << p[right] << endl;
    if(p[midd] == x){
      cout << 0 << endl;
      return;
    }
    if(x > p[midd]) left = midd;
    else right = midd;
    // cout << "after\t" << p[left] << " " << p[midd] << " " << p[right] << endl;
  }

  // cout << p[right] << " - "<< p[left] << endl;
  cout << p[right] - p[left] << endl;

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  generatePrimes();
  int k;
  while (cin >> k && k != 0) {
    solve(k);
  }
}