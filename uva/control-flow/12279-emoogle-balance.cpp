#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc, ev, dd, dg;
  dd=dg=0;
  cin >> tc;
  int i = 0;
  while(i++, tc != 0){
    while(tc--){
      cin >> ev;
      if(1 <= ev and ev <= 99)
        dd++;
      if(ev == 0)
        dg++;
    }
    printf("Case %d: %d\n", i, dd - dg);
    cin >> tc;
    dd=dg=0;
  }
}