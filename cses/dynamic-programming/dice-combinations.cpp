#include<bits/stdc++.h>

using namespace std;


vector<long long int> dp;

long long int comb(long long int n){
  /*cout << "n: " << n;*/
  if(n <= 1) {
    return 1;
  }

  if(dp[n] == -1){
    dp[n] = 0;
    for(long long int i = 1; i <= n && i <= 6; i++){
      dp[n] += comb(n - i);
    }
  }
  /*cout << "valor: " << dp[n];*/
  return dp[n] % (1000000007);
}

int main(){
  long long int n; cin >> n;
  dp.assign(n + 1, -1);
  cout << comb(n);
}
