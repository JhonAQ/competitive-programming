#include<bits/stdc++.h>

using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    int n;cin >> n;
    int alt = 0;
    int racha = 0;
    bool easy = false;
    while(n--){
      char cell; cin >> cell;
      if(cell == '.'){
        alt++;
        racha++;
      }else{
        racha = 0;
      }
      if(racha == 3){
        easy = true;
      }
    }
    if(easy){
      cout << 2 << endl;
    }else{
      cout << alt << endl;
    }
  }
}
