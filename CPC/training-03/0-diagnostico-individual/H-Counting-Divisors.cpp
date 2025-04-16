#include<bits/stdc++.h>

using namespace std;

int countDivisors(int n){
  int count = 0;
  for(int i = 1; i * i <= n; i++){
    if(n%i==0){
      count += 2;
      if(i * i == n) count--;
    }
  }
  return count;
}

int main(){
  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    // cout << n << endl;
    cout << countDivisors(n) << endl;
  }
}