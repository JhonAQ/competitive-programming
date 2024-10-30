#include<bits/stdc++>

using namespace std;

int main(){
  long long n; cin >> n;
  const int MOD = 1000000007;
  vector<long long> dado = {1, 2, 3, 4, 5, 6};
  vector<long long> memo(n + 1, 0);
  memo[0] = 1;
  for(long long i = 1; i <= n; i++){
    for(long long num : dado){
        if(i - num >= 0){
          memo[i] += memo[i - num] % MOD;
        }
    }
  }
  cout << memo[n] % MOD;
}

