#include<bits/stdc++.h>

using namespace std;

bitset<1000010> isP;

void sieve(){
  isP.set();
  isP[0] = isP[1] = 0;
  for(int i = 2; i * i < 1000000; i++){
    if(isP[i]){
      for(int j = i * i; j < 1000000; j+=i){
        isP[j] = 0;
      }
    }
  }
}

bool isEmirp(int n){
  string str = to_string(n);
  string reversed = string(str.rbegin(), str.rend());
  return str.size() > 1 && isP[stoi(reversed)] && str != reversed;
}

void solve(int n){
  if(isP[n]){
    if(isEmirp(n)) cout << n << " is emirp.";
    else cout << n <<  " is prime.";
  }
  else cout << n << " is not prime.";

}

int main(){
  sieve();
  int n;
  while(cin >> n){
    solve(n);
    cout << endl;
  }
}