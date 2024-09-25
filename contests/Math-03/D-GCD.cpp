#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

int solve(int n){
  int ans = 0;
  for(int i = 1; i < n; ++i){
    for(int j = i + 1; j <=n; j++){
      ans += gcd(max(i,j), min(i,j));
    }
  }
  return ans;
}

int main(){
  int n;
  while(cin >> n && n){
    cout << solve(n) << endl;
  }
}