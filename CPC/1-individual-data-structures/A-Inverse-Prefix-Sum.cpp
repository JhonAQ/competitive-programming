#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;
  int prev = 0;
  while(tc--){
    int act; cin >> act;
    cout << act - prev;
    if(tc) cout << " ";
    prev = act;
  }
}
