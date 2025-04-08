#include<bits/stdc++.h>

using namespace std;

vector<bool> isPrime(1e9 + 1, false);

void chargePrimes(){
  for(int i = 2; i <= 1e9; i++){
    if(isPrime[i]){
      for(int j = i + i; j <= 1e9; j = j + i){
        isPrime[j] = false;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--){
    int x, k;
    if(k > 1){
      if(k == 2 && x == 1){
        cout << "YES" << endl;
      }
    }else if(k == 1 && isPrime[x]){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }
}
