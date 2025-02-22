#include<bits/stdc++.h>

using namespace std;

int res(int x, int y){
  if(x > y){
    return 2 * x - 1;
  }
  return 2 * y;
}

int main(){
  int tc; cin >> tc;

  while(tc--){
    double x, y, k; cin >> x >> y >> k;
    int pasx = ceil(x / k);
    int pasy = ceil(y / k);
    cout << res(pasx, pasy) << endl;
  }
}
