#include<bits/stdc++.h>

using namespace std;
vector<int> coins;
vector<int> dp;
vector<bool> isFound;
const int MOD = 1000000007;

int totalPaths(int x){
  if(isFound[x]) return dp[x];
  if(x < 0) return 0;
	for(int moneda : coins){
    dp[x] = (dp[x] + totalPaths(x - moneda))% MOD;
	}
	isFound[x]  = true;
	return dp[x];
}

int main(){
  int n, x; cin >> n >> x;
	dp.assign(x + 1, 0);
	isFound.assign(x + 1, false);
	isFound[0] = true;
	dp[0] = 1;
	for(int i = 0; i < n; i++){
	  int c; cin >> c;
	  coins.push_back(c);
	}
	cout << totalPaths(x) << endl;
  
  /*for(int i : dp){*/
  /*  cout << i << endl;*/
  /*}*/
}
