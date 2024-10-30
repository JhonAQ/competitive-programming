#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, s, k; cin >> n >> s >> k;
  int total = 0;
  while(n--){
    int a, b; cin >> a >> b;
    total += a * b;
  }
  if(total < s) total += k;
  cout << total;
}