#include <bits/stdc++.h>

using namespace std;
vector<unsigned long long> fac(21, 1);

void preprocess() {
  for (int i = 2; i <= 20; i++) {
    for (int j = 2; j <= i; j++) {
      fac[i] *= j;
    }
  }
}

void solve(string s) {
  int k, len = s.length(), group;
  vector<string> ans(len, "void");
  vector<int> idx(len + 1, 31);
  cin >> k;
  for(int i = len; i >= 1; i--){
    group = ceil(double(k)/fac[i-1]);
    idx[len - i] = group;
    // cout << idx[len - i] << " ";
    k %= fac[i - 1];
  }
  for(int i = 0; i < len; i++){
    int pos = idx[i];
    // cout << pos << " ";
    int j = 0;
    while(pos && j < len){
      if(ans[j] == "void") pos--;
      j++;
    }
    cout << j << " ";
    // ans[j] = "asdf";
    // cout << ans[j];
    // ans[j];
    ans[j] = "asdf";
  }
}
int main() {
  preprocess();
  int tc, i = 0;
  cin >> tc;
  while (i++ < tc) {
    cout << "Case " << i << ": ";
    string aaaaaa;
    cin >> aaaaaa;
    solve(aaaaaa);
  }
}