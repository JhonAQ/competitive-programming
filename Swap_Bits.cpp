#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int mask; cin >> mask;
    for(int i = 0; i < 30 >> 1; i++){
      int b = mask & (1<<(i << 1));
      int a = mask & (1<<(i << 1 + 1));
      if(a)
        mask = mask | (1<<(i << 1));
      else
        mask = mask & ~(1 << (i << 1));
      if(b)
        mask = mask | (1<<((i << 1) + 1));
      else
        mask = mask & ~(1 << (i << 1 + 1));
    }
    cout << mask << endl;
  }
}