#include<bits/stdc++.h>

using namespace std;

int main(){
  int l, r;
  scanf("%d\n%d", &l, &r);
  int mask = l ^ r;
  int pos = 0;

  // cout << "mask:\t" <<mask << endl;
  while(mask){
    mask >>= 1;
    pos++;
  }
  // cout << pos << endl;
  int ans = 0;
  for(int i = 0; i < pos; i++){
    ans += 1 << i;
  }
  cout << ans;
}