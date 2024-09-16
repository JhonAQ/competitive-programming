#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int mask10 = 0xAAAAAAAAAA;
    int mask01 = 0x5555555555;
    mask10 &= n;
    mask01 &= n;
    // cout << endl << "mask10: " << bitset<32>(mask10) << endl;
    // cout << endl << "mask01: " << bitset<32>(mask01) << endl;
    mask01 <<= 1;
    mask10 >>= 1;
    // cout << endl << "mask10: " << bitset<32>(mask10) << endl;
    int ans = mask01 | mask10;
    cout << ans << endl;
  }
}