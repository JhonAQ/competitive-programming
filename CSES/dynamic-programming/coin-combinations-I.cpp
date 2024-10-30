#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, x; cin >> n >> x;
  int MOD = 1000000007;
  vector<int> coins;
	int dp[x + 1];
	memset(dp, 0, sizeof(dp));
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    coins.push_back(c);
  }
  dp[0] = 1;
  for(int i = 1; i <= x; i++){
    for(int moneda : coins){
      if(moneda > i) continue;
      if(i - moneda >=0){
        dp[i] = (dp[i] + dp[i - moneda]) % MOD;
      }
    }
  }
  cout << dp[x] << endl;
}
