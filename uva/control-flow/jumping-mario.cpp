#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;
  for(int i = 1; i <= tc; i++){
    int h = 0, l = 0, ac, nx, n; cin >> n;
    cin >> ac;
    for(int j = 0; j < n - 1; j++){
      cin >> nx;
      if(nx > ac) h++;
      if(ac > nx) l++;
      ac = nx;
    }
    printf("Case %d: %d %d\n", i, h, l);
  }
}