#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

unsigned main(){
  int n, k, l; cin >> n >> k >> l;
  if(2*l < k){
    cout << n*(4*l*l)<<endl;
  }else{
    cout << k * (4*l - k)*(n - 1) + 4 *l*l << endl;
  }
}
